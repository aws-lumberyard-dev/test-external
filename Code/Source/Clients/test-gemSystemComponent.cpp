
#include "test-gemSystemComponent.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

namespace test_gem
{
    void test_gemSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<test_gemSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<test_gemSystemComponent>("test_gem", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void test_gemSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("test_gemService"));
    }

    void test_gemSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("test_gemService"));
    }

    void test_gemSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void test_gemSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    test_gemSystemComponent::test_gemSystemComponent()
    {
        if (test_gemInterface::Get() == nullptr)
        {
            test_gemInterface::Register(this);
        }
    }

    test_gemSystemComponent::~test_gemSystemComponent()
    {
        if (test_gemInterface::Get() == this)
        {
            test_gemInterface::Unregister(this);
        }
    }

    void test_gemSystemComponent::Init()
    {
    }

    void test_gemSystemComponent::Activate()
    {
        test_gemRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void test_gemSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        test_gemRequestBus::Handler::BusDisconnect();
    }

    void test_gemSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace test_gem

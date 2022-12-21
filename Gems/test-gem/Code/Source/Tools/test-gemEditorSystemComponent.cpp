
#include <AzCore/Serialization/SerializeContext.h>
#include "test-gemEditorSystemComponent.h"

namespace test_gem
{
    void test_gemEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<test_gemEditorSystemComponent, test_gemSystemComponent>()
                ->Version(0);
        }
    }

    test_gemEditorSystemComponent::test_gemEditorSystemComponent() = default;

    test_gemEditorSystemComponent::~test_gemEditorSystemComponent() = default;

    void test_gemEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("test_gemEditorService"));
    }

    void test_gemEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("test_gemEditorService"));
    }

    void test_gemEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void test_gemEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void test_gemEditorSystemComponent::Activate()
    {
        test_gemSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void test_gemEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        test_gemSystemComponent::Deactivate();
    }

} // namespace test_gem

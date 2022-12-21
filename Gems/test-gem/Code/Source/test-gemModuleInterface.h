
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>
#include <Clients/test-gemSystemComponent.h>

namespace test_gem
{
    class test_gemModuleInterface
        : public AZ::Module
    {
    public:
        AZ_RTTI(test_gemModuleInterface, "{0FE61679-6160-486C-AB11-B1C28745DC0E}", AZ::Module);
        AZ_CLASS_ALLOCATOR(test_gemModuleInterface, AZ::SystemAllocator, 0);

        test_gemModuleInterface()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                test_gemSystemComponent::CreateDescriptor(),
                });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<test_gemSystemComponent>(),
            };
        }
    };
}// namespace test_gem

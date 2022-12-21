
#include <test-gemModuleInterface.h>
#include "test-gemEditorSystemComponent.h"

namespace test_gem
{
    class test_gemEditorModule
        : public test_gemModuleInterface
    {
    public:
        AZ_RTTI(test_gemEditorModule, "{591BD88C-4386-4A81-8E8F-3AB174859279}", test_gemModuleInterface);
        AZ_CLASS_ALLOCATOR(test_gemEditorModule, AZ::SystemAllocator, 0);

        test_gemEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                test_gemEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<test_gemEditorSystemComponent>(),
            };
        }
    };
}// namespace test_gem

AZ_DECLARE_MODULE_CLASS(Gem_test_gem, test_gem::test_gemEditorModule)

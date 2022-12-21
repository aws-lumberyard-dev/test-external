
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "test-projectSystemComponent.h"

namespace test_project
{
    class test_projectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(test_projectModule, "{00786C1A-CE4B-4E3C-8438-8EA5922351E1}", AZ::Module);
        AZ_CLASS_ALLOCATOR(test_projectModule, AZ::SystemAllocator, 0);

        test_projectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                test_projectSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<test_projectSystemComponent>(),
            };
        }
    };
}// namespace test_project

AZ_DECLARE_MODULE_CLASS(Gem_test_project, test_project::test_projectModule)

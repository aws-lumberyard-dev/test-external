
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>
#include <Clients/${NameLower}SystemComponent.h>

namespace ${SanitizedCppName}
{
    class ${SanitizedCppName}ModuleInterface
        : public AZ::Module
    {
    public:
        AZ_RTTI(${SanitizedCppName}ModuleInterface, "{0FE61679-6160-486C-AB11-B1C28745DC0E}", AZ::Module);
        AZ_CLASS_ALLOCATOR(${SanitizedCppName}ModuleInterface, AZ::SystemAllocator, 0);

        ${SanitizedCppName}ModuleInterface()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                ${SanitizedCppName}SystemComponent::CreateDescriptor(),
                });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<${SanitizedCppName}SystemComponent>(),
            };
        }
    };
}// namespace ${SanitizedCppName}

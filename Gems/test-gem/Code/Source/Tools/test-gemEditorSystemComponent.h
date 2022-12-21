
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <Clients/test-gemSystemComponent.h>

namespace test_gem
{
    /// System component for test_gem editor
    class test_gemEditorSystemComponent
        : public test_gemSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = test_gemSystemComponent;
    public:
        AZ_COMPONENT(test_gemEditorSystemComponent, "{8A82E3D7-B5AD-4ADF-AB15-D3468426E7F8}", BaseSystemComponent);
        static void Reflect(AZ::ReflectContext* context);

        test_gemEditorSystemComponent();
        ~test_gemEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace test_gem


#pragma once

#include <AzCore/Component/Component.h>

#include <test-project/test-projectBus.h>

namespace test_project
{
    class test_projectSystemComponent
        : public AZ::Component
        , protected test_projectRequestBus::Handler
    {
    public:
        AZ_COMPONENT(test_projectSystemComponent, "{D1BFF425-9CF9-4EED-BBBC-FE708A8321B8}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        test_projectSystemComponent();
        ~test_projectSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // test_projectRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}


#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace test_project
{
    class test_projectRequests
    {
    public:
        AZ_RTTI(test_projectRequests, "{E5500A3D-F85D-4421-A644-616CD34E5CE4}");
        virtual ~test_projectRequests() = default;
        // Put your public methods here
    };

    class test_projectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using test_projectRequestBus = AZ::EBus<test_projectRequests, test_projectBusTraits>;
    using test_projectInterface = AZ::Interface<test_projectRequests>;

} // namespace test_project



#include <test-gemModuleInterface.h>
#include "test-gemSystemComponent.h"

namespace test_gem
{
    class test_gemModule
        : public test_gemModuleInterface
    {
    public:
        AZ_RTTI(test_gemModule, "{591BD88C-4386-4A81-8E8F-3AB174859279}", test_gemModuleInterface);
        AZ_CLASS_ALLOCATOR(test_gemModule, AZ::SystemAllocator, 0);
    };
}// namespace test_gem

AZ_DECLARE_MODULE_CLASS(Gem_test_gem, test_gem::test_gemModule)

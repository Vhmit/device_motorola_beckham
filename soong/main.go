package beckham

import (
    "android/soong/android"
)

func init() {
    android.RegisterModuleType("motorola_beckham_init_library_static", initLibraryFactory)
}

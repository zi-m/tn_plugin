#include <tn_plugin.h>


bool TN_Plugin::load_lib(const char* env_name, const char* dll_stem)
{
    boost::filesystem::path path;
    if(const char* env = getenv(env_name))
        path = env;
    else
        return false;

    path /= dll_stem;
    path += boost::dll::shared_library::suffix();

    if(!boost::filesystem::exists(path))
        return false;

    load_lib(path);
    return true;
}

void TN_Plugin::load_lib(const boost::filesystem::path& path)
{
    try
    {
        m_lib = boost::dll::shared_library{ path };
    }
    catch(...)
    {
        TN_THROW_WITH_NESTED("TN_Plugin::load_lib '{}' failed", path.generic_string());
    }
}

TN_Plugin::TN_Plugin(const boost::filesystem::path& path)
{
    load_lib(path);
}

#ifndef TN_PLUGIN_H
#define TN_PLUGIN_H

#include <tn_log.h>
#include <boost/dll.hpp>


class TN_Plugin
{
public:

    explicit TN_Plugin() = default;
    explicit TN_Plugin(const boost::filesystem::path& path);

protected:

    template<typename T>
    T* get_fn(const char* symbol_name)
    {
        try
        {
            return m_lib.get<T>(symbol_name);
        }
        catch(...)
        {
            throw TN_RUNTIME_ERROR("TN_Plugin.get_fn '{}' failed", symbol_name);
        }
    }

    bool load_lib(const char* env_name, const char* dll_stem);
    void load_lib(const boost::filesystem::path& path);

private:

    boost::dll::shared_library m_lib;
};

#endif

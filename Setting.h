///////////////////////////////////////////////////////////////
//  SettingTemplate Class
// 
#include <wx/config.h>


template <class T>
class TSetting : public wxConfig
{
public:
	TSetting()
	{
	}

    TSetting( const wxString& config_name, const wxString& name, const T& default_value ) :
        wxConfig( config_name )
    {
        m_szName = name;
        m_TDefaultValue = default_value;
        if ( !Load() ) Save();
    }

    virtual ~TSetting()
    {
    }

    bool SetValue( const T& value )
    { 
        m_TValue = value;
        return Save();
    }

    bool SetToDefaultValue()
    { 
        m_TValue = m_TDefaultValue;
        return Save();
    }

    wxString GetName()
    {
        return m_szName;
    }

    T GetValue()
    { 
        Load();
        return m_TValue; 
    }

    T GetDefaultValue()
    { 
        return m_TDefaultValue; 
    }

    bool Is( const T& value )
    { 
        Load();
        return m_TValue == value; 
    }

protected:
    bool Load()
    {
        return wxConfig::Read( m_szName, &m_TValue, m_TDefaultValue );
    }

    bool Save()
    {
        return wxConfig::Write( m_szName, m_TValue );
    }

private:
    wxString m_szName;
    T m_TDefaultValue;
    T m_TValue;
};

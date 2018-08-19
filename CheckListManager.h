#include "Singleton.h"
#include "CRIRegistryConstant.h"
#include "CRIRegistryOptions.h"
#include "db/dbSingleton.h"
#include "db/dbClass.h"
#include "dbClass/CUser.h"
#include "MyFunctions.h"
#include "CRIRegistryCheckListDlg.h"

class CheckListManager: public Singleton<CheckListManager, CheckListManager>
{
public:
    ~CheckListManager();
    void Show(const wxString& type);
    void Control(const wxString& type);
    bool Create(const wxString& type);

protected:
    CheckListManager();

private:
	friend Singleton<CheckListManager, CheckListManager>;
};


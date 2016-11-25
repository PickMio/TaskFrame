
#include "stdafx.h"

#include <iostream>
#include <time.h>

#include "TService.h"
#include "ReachCountTaskConfiger.h"
#include "ReachCountTaskData.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    TService service;

    auto taskdata = make_shared<ReachCountTaskData>();
    auto task = make_shared<CTask>();
    task.get()->setTaskData(taskdata);

    if (!service.addTask(task)){
        cout << "error " << endl;
    }

    service.updateProgress(0, 12);
    return 0;
}


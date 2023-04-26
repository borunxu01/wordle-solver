#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please

#endif

#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here
bool scheduleHelper(const AvailabilityMatrix& avail, const size_t& dailyNeed, const size_t& maxShifts, DailySchedule& sched, size_t day, size_t worker, std::map<Worker_T, int> workerShifts);



// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below
    std::map<Worker_T, int> workerShifts;
    for (size_t i = 0; i < avail[0].size(); i++) 
    {
        workerShifts[i] = 0;
    }

    return scheduleHelper(avail, dailyNeed, maxShifts, sched, 0, 0, workerShifts);
   


}

bool scheduleHelper(const AvailabilityMatrix& avail, const size_t& dailyNeed, const size_t& maxShifts, DailySchedule& sched, size_t day, size_t worker, std::map<Worker_T, int> workerShifts) {
    if (day == avail.size()) 
    {
        return true;
    }

    if (worker == avail[day].size()) 
    {
        return false;
    }

    bool result = scheduleHelper(avail, dailyNeed, maxShifts, sched, day, worker + 1, workerShifts);
    if (!result && avail[day][worker] && workerShifts[worker] < maxShifts) 
    {
        if (sched.size() <= day) 
        {
            sched.push_back(std::vector<Worker_T>());
        }
        sched[day].push_back(worker);
        workerShifts[worker]++;

        if (sched[day].size() < dailyNeed) 
        {
            result = scheduleHelper(avail, dailyNeed, maxShifts, sched, day, worker + 1, workerShifts);
        } 
        else 
        {
            result = scheduleHelper(avail, dailyNeed, maxShifts, sched, day + 1, 0, workerShifts);
        }

        if (!result) 
        {
            sched[day].pop_back();
            workerShifts[worker]--;
        }
    }

    return result;
}
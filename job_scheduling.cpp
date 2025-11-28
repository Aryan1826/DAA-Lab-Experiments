#include <iostream>
#include <algorithm>
using namespace std;
struct Job
{
    int deadline;
    int profit;
};
int main()
{
    int size;
    cout << "Enter total job count";
    cin >> size;
    Job jobs[size];
    int max;
    cout << "Enter job details";
    for (int i = 0; i < size; i++)
    {
        cout << "enter job " << i + 1 << " deadline";
        cin >> jobs[i].deadline;
        cout << "enter job " << i + 1 << " profit";
        cin >> jobs[i].profit;
        if (i == 0)
        {
            max = jobs[i].deadline;
        }
        else
        {
            if (max < jobs[i].deadline)
            {
                max = jobs[i].deadline;
            }
        }
    }
    sort(jobs, jobs + size, [](const Job &a, Job &b)
         { return a.profit > b.profit; });

    int slots[max];
    Job selectedJobs[max];

    for (int i = 0; i < max; i++)
    {
        slots[i] = 0;
    }

    // int current_allocated = 0;
    int total_profit = 0;
    // int j = 0;
    for (int i = 0; i < size; i++)
    {
        // if ((max - current_allocated) >= jobs[i].deadline)
        // {
        //     selectedJobs[j++] = jobs[i];
        //     current_allocated += jobs[i].deadline;
        //     total_profit += jobs[i].profit;
        // }
        // if (current_allocated == max)
        // {
        //     break;
        // }
        int s = jobs[i].deadline;
        for (int k = s - 1; k >= 0; k--)
        {
            if (slots[k] == 0)
            {
                slots[k] = 1;
                total_profit += jobs[i].profit;
                selectedJobs[k] = jobs[i];
                break;
            }
        }
    }
    cout << "total profit" << total_profit << endl;
    cout << "selected jobs" << endl;
    for (int i = 0; i < max; i++)
    {
        cout << selectedJobs[i].profit << "(" << selectedJobs[i].deadline << ")" << endl;
    }

    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
struct item
{
    int wt;
    int val;
    double ratio;
};
int main()
{
    int size;
    cout << "Enter total items:";
    cin >> size;
    item items[size];
    cout << "Enter details of items:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter item[" << i << "] wt: ";
        cin >> items[i].wt;
        cout << "Enter item[" << i << "] val: ";
        cin >> items[i].val;
        items[i].ratio = items[i].val / items[i].wt;
    }
    sort(items, items + size, [](const item &a, const item &b)
         { return a.ratio > b.ratio; });

    int capacity;
    cout << "Enter total capacity";
    cin >> capacity;

    int current_weight = 0;
    int total_value = 0;
    item selected_items[size];
    int sIndex = 0;
    for (int i = 0; i < size; i++)
    {
        if (current_weight + items[i].wt <= capacity)
        {
            selected_items[sIndex++] = items[i];
            current_weight += items[i].wt;
            total_value += items[i].val;
        }
    }
    cout << "Selected items:" << endl;
    for (int i = 0; i < sIndex; i++)
    {
        cout << selected_items[i].wt << " " << selected_items[i].val << endl;
    }
    cout << "total value" << total_value;
    cout << "wt picked:" << current_weight;

    return 0;
}
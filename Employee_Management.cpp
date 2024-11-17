#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;

public:
    int empId;
    void InputBasicInfo()
    {
        cout << "Enter Employee ID: ";
        cin >> empId;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);
    }

    void DisplayBasicInfo() const
    {
        cout << endl;
        cout << "Employee ID: " << empId << endl;
        cout << "Employee Name: " << name << endl;
    }

    virtual void inputInfo() = 0;
    virtual void calculateSalary() = 0;
    virtual void increament() = 0;
    virtual void leave() = 0;
};

class VisitingEmp : public Employee
{
private:
    int numberOfDays;
    float dailyWages;
    float salary;

public:
    void inputInfo() override
    {
        cout << "Enter Daily Wages: ";
        cin >> dailyWages;
        cout << "Enter Number of Days: ";
        cin >> numberOfDays;
    }

    void calculateSalary()
    {
        salary = dailyWages * numberOfDays;
        cout << "Salary: " << salary << endl;
        cout << "Employee Type: Temporary" << endl;
    }
    void increament() override
    {
        cout << "Enter new Daily Wages: ";
        cin >> dailyWages;
        int wish;
        do
        {
            cout << "Do you want to change number of days also" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cin >> wish;
            switch (wish)
            {
            case 1:
                cout << "Enter Number of Days: ";
                cin >> numberOfDays;
                break;
            case 2:
                break;
            default:
                cout << "Invalid Choice. Please enter a valid number." << endl;
                continue;
            }
        } while (wish != 1 && wish != 2);
        salary = dailyWages * numberOfDays;
    }
    void leave() override
    {
        int holiday;
        cout << "Enter Number of leaves: ";
        cin >> holiday;
        numberOfDays -= holiday;

        if (numberOfDays < 0)
        {
            numberOfDays = 0;
        }

        salary = (dailyWages * numberOfDays);
    }
};

class PermanentEmp : public Employee
{
private:
    int monthlySalary;

public:
    void inputInfo() override
    {
        cout << "Enter Monthly Salary: ";
        cin >> monthlySalary;
    }

    void calculateSalary()
    {
        cout << "Salary: " << monthlySalary << " Per Month" << endl;
        cout << "Employee Type: Permanent" << endl;
    }
    void increament() override
    {
        float change;
        cout << "Enter the increament percentage: ";
        cin >> change;
        monthlySalary += ((change / 100) * monthlySalary);
    }
    void leave() override
    {
        int holiday;
        cout << "Enter the number of leaves: ";
        cin >> holiday;
        monthlySalary -= ((monthlySalary / 30) * holiday);
    }
};

int main()
{
    const int MAX_EMPLOYEES = 10;
    Employee *employees[MAX_EMPLOYEES] = {nullptr};
    int numEmployees = 0;

    int choice;
    bool found = false;
    bool q = false;

    do
    {
        cout << endl;
        cout << "-------- Main Menu ----------" << endl;
        cout << "1. Create Visiting Employee" << endl;
        cout << "2. Create Permanent Employee" << endl;
        cout << "3. Get Information By Employee Id" << endl;
        cout << "4. Get Information of All Employees" << endl;
        cout << "5. To give the increament" << endl;
        cout << "6. To fire the employee" << endl;
        cout << "7. To evalute salary according to the leaves" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (numEmployees < MAX_EMPLOYEES)
            {
                employees[numEmployees] = new VisitingEmp();
                numEmployees++;
            }
            else
            {
                cout << "Maximum number of employees reached!\n";
            }
            break;
        case 2:
            if (numEmployees < MAX_EMPLOYEES)
            {
                employees[numEmployees] = new PermanentEmp();
                numEmployees++;
            }
            else
            {
                cout << "Maximum number of employees reached!\n";
            }
            break;
        case 3:
            int id;
            cout << "Enter Employee Id: ";
            cin >> id;
            for (int i = 0; i < numEmployees; i++)
            {
                if (employees[i]->empId == id)
                {
                    employees[i]->DisplayBasicInfo();
                    employees[i]->calculateSalary();
                    found = true;
                }
            }
            if (found != true || q == true)
            {
                cout << "Employee with ID " << id << " not found in the record.." << endl;
            }
            break;
        case 4:
            if (numEmployees != 0)
            {
                cout << "\nAll Employees Information\n";
                for (int i = 0; i < numEmployees; i++)
                {
                    employees[i]->DisplayBasicInfo();
                    employees[i]->calculateSalary();
                    cout << endl;
                }
            }
            else
            {
                cout << "No Employees in the system" << endl;
            }
            break;
        case 5:
            int emid;
            cout << "Enter Employee Id: ";
            cin >> emid;
            for (int i = 0; i < numEmployees; i++)
            {
                if (employees[i]->empId == emid)
                {
                    employees[i]->increament();
                    found = true;
                }
            }
            if (found != true)
            {
                cout << "Employee with ID " << emid << " not found in the record.." << endl;
            }
            break;
        case 6:
            int k;
            cout << "Enter id: ";
            cin >> k;
            for (int i = 0; i < numEmployees; i++)
            {
                if (employees[i]->empId == k)
                {
                    employees[i]->empId = -1;
                    delete employees[i];
                    numEmployees--;
                    q = true;
                    found = true;
                }
            }
            if (found != true)
            {
                cout << "Employee with ID " << k << " not found in the record.." << endl;
            }
            break;
        case 7:
            int y;
            cout << "Enter Employee Id: ";
            cin >> y;
            for (int i = 0; i < numEmployees; i++)
            {
                if (employees[i]->empId == y)
                {
                    employees[i]->leave();
                    found = true;
                }
            }
            if (found != true)
            {
                cout << "Employee with ID " << y << " not found in the record.." << endl;
            }
            break;

            break;

        case 0:
            cout << "Exiting The Program\n";
            break;
        default:
            cout << "Invalid Number: Please Enter a Valid Number\n";
            continue;
        }

        if (choice != 0 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
        {
            Employee *emp = employees[numEmployees - 1];
            emp->InputBasicInfo();
            emp->inputInfo();
        }

    } while (choice != 0);

    for (int i = 0; i < numEmployees; i++)
    {
        delete employees[i];
    }

    return 0;
}
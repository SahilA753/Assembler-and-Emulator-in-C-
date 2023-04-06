#include <bits/stdc++.h>
using namespace std;

int mainmemory_limit=pow(2,24);
string file_name;
fstream _file;
int LIMIT = 100000;
int t = 0;
int stackLimit = 1 << 23;
int PC = 0, SP = 0, registerA = 0, registerB = 0;
vector<int> objectFile;
vector<string> mnemonics = {"ldc", "adc", "ldl", "stl", "ldnl",
 "stnl","add","sub", "shl", "shr", "adj", "a2sp", "sp2a", "call",
 "return","brz", "brlz","br", "HALT"};

void main_execution(int opcode, int Value,int mainMemory[])
{
    if(opcode==0)
    {
        registerB = registerA;
        registerA = Value;
    }
    if(opcode==1)
    {
        registerA += Value;
    }
    if(opcode==2)
    {
        registerB = registerA;
        registerA = mainMemory[SP + Value];  
    }
    if(opcode==3)
    {
        mainMemory[SP + Value] = registerA;
        registerA = registerB;
    }
    if(opcode==4)
    {
        registerA = mainMemory[registerA + Value];
    }
    if(opcode==5)
    {
        mainMemory[registerA + Value] = registerB;
    }
    if(opcode==6)
    {
        registerA = registerB + registerA;
    }
    if(opcode==7)
    {
        registerA = registerB - registerA;
    }
    if(opcode==8)
    {
        registerA = registerB << registerA;
    }
    if(opcode==9)
    {
        registerA = registerB >> registerA;
    }
    if(opcode==10)
    {
        SP = SP + Value; 
    }
    if(opcode==11)
    {
        SP = registerA;
        registerA = registerB;
    }
    if(opcode==12)
    {
        registerB = registerA;
        registerA = SP;
    }
    if(opcode==13)
    {
        registerB = registerA;
        registerA = PC;
        PC = Value - 1;
    }
    if(opcode==14)
    {
        PC = registerA;
        registerA = registerB;
    }
    if(opcode==15)
    {
        if (registerA == 0)
        {
            PC = PC + Value;
        }
    }
    if(opcode==16)
    {
       if (registerA < 0)
        {
            PC = PC + Value;
        } 
    }
    if(opcode==17)
    {
         PC = PC + Value;
    }
    if(opcode<0||opcode>17)
    {
        cout << "Invalid opcode. Input valid machine code!";
        exit(0);   
    }
   
    
}
string to_hex(int value, int len)
{
    stringstream obj;
    obj << hex << value;
    string result(obj.str());
    reverse(result.begin(), result.end());
    while ((int)result.size() > len)
    {
        result.pop_back();
    }
    while ((int)result.size() < len)
    {
        result.push_back('0');
    }
    reverse(result.begin(), result.end());
    return result;
}


int argumentrun(int mainMemory[])
{
    //SEGMENTATION FAULT
    if (PC >= (int)objectFile.size())
    {
        cout << "Segmentation fault.";
        exit(0);
    }

    int opcode = 0xFF & objectFile[PC]; // last 8 bits
    int operand = objectFile[PC] >> 8;  // first 24 bits

    if (opcode == 18) // HALT
    {
        t++;
        return 0;
    }

    cout << mnemonics[opcode] << "\t";
    printf("%08X\n", operand);

    main_execution(opcode, operand,mainMemory);

    cout<<"A = "<<setw(8)<<setfill('0')<<registerA<<", B = "<<setw(8)<<setfill('0')<<registerB<<", PC = "<<setw(8)<<setfill('0')<<PC<<", SP = "<<setw(8)<<setfill('0')<<SP;

    _file << "A = " << to_hex(registerA, 8) << ", B = " << to_hex(registerB, 8) << ", PC = " << to_hex(PC, 8) << ", SP = " << to_hex(SP, 8) << endl;

    t++;
    PC++;
     
     //INFINITE LOOP
     if (t > LIMIT)
    {
        cout << "Infinite loop detected.";
        exit(0);
    }
     //STACK OVERFLOW
    if (SP > stackLimit)
    {
        cout << "Stack overflow.";
        exit(0);
    }

    return 1;
}

pair<long long, bool> read_operand(string &operand)
{
    int len = (int)operand.size();

    if (len == 0)
    {
        return {0, 0};
    }

    char *str = (char *)malloc(len * sizeof(char));

    for (int i = 0; i < len; i++)
    {
        str[i] = operand[i];
    }
    for (int i = len; i < strlen(str); i++)
    {
        str[i] = '\0';
    }

    char *end;
    long long num;

    num = strtol(str, &end, 10); 
    if (!*end)
    {
        return {num, 1};
    }

    num = strtol(str, &end, 16); 
    if (!*end)
    {
        return {num, 1};
    }

    return {-1, 0};
}

int advance(int mainMemory[])
{
    cout << "Emulator input: ";
    string input;
    cin >> input;

    for (int i = 0; i < input.size(); i++)
        input[i] = tolower(input[i]);

    if (input == "-t")
    {
        if (argumentrun(mainMemory) == 0)
            cout << "HALT instruction! No furthur tracing possible.\n";
    }
    else if (input == "-A")
    {
        if (argumentrun(mainMemory) == 0)
            cout << "HALT instruction! No furthur tracing possible.\n";
        else
        {
            while (argumentrun(mainMemory) == 1)
            {
            }
        }
    }
    else if (input == "-d")
    {
        string operand, offset;

        cout << "Base address: ";
        cin >> operand;

        int baseAddress = read_operand(operand).first;

        cout << "No. of values: ";
        cin >> offset;

        auto value = read_operand(offset);

        int i = baseAddress;
        while (i < baseAddress + value.first && i < (1 << 24))
        {
            printf("%08X \t %08x\n", i, mainMemory[i]);
            i++;
        }
    }
    else if (input == "-X")
    {
        return 0;
    }
    else
    {
        cout << "Invalid emulator input." << endl;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    int mainMemory[mainmemory_limit];

    if (argc < 2)
    {
        cout << "Error: Input valid file name" << endl;
        return 0;
    }

    int temp;

    string __file = argv[1];

    ifstream file(__file, ios::in | ios::binary);
    while (file.read((char *)&temp, sizeof(int)))
    {
        objectFile.push_back(temp);
    }

    for (int i = 0; i < __file.length(); i++)
    {
        if (__file[i] == '.')
            break;
        file_name.push_back(__file[i]);
    }

    //INITIALIZING
    _file.open(file_name + ".txt", ios::out);

    int i = 0;
    for (auto x : objectFile)
    {
        mainMemory[i] = x;
        i++;
    }

    cout<<"One by one instruction set: -t"<<endl;
    cout<<"All at once instruction set: -A"<<endl;
    cout<<"See memory: -d"<<endl;
    cout<<"Exit: -X"<<endl;

    while (true)
    {
        if (advance(mainMemory) == 1)
        {
            continue;
        }
        break;
    }

    _file.close();
    cout << "Total instructions : " << t << endl;
    return 0;
}
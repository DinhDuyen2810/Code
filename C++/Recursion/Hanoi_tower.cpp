#include <iostream>

using namespace std;

void move(char start, char finish, char mediate, int disk)
{
    if(disk == 1){
        cout << "Move " << start << " to " << finish << endl;
        return;
    }
    move(start, mediate, finish, disk - 1);
    move(start, finish, mediate, 1);
    move(mediate, finish, start, disk - 1);
}
int main()
{
    int disk;
    cout << "Nhap so dia ban muon: ";
    cin >> disk;
    move('A', 'B', 'C', disk);
}
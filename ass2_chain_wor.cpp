#include<iostream>
#include<stdlib.h>
#define MAX 10
using namespace std;

class WO_chain {
private:
    int a[MAX][2];
public:
    WO_chain();
    int create(int);
    void chain(int, int);
    void display();
};

WO_chain::WO_chain() {
    for(int i = 0; i < MAX; i++) {
        a[i][0] = -1;
        a[i][1] = -1;
    }
}

int WO_chain::create(int num) {
    return num % 10;
}

void WO_chain::chain(int key, int num) {
    int flag, i, count = 0, ch;
    flag = 0;
    i = 0;
    while(i < MAX) {
        if(a[i][0] != -1)
            count++;
        i++;
    }
    if(count == MAX) {
        cout << "\nHash Table Is Full";
        display();
        exit(1);
    }
    if(a[key][0] == -1)
        a[key][0] = num;
    else {
        ch = a[key][1];
        if(ch == -1) {
            for(i = key + 1; i < MAX; i++) {
                if(a[i][0] == -1) {
                    a[i][0] = num;
                    a[key][1] = i;
                    flag = 1;
                    break;
                }
            }
        }
        else {
            while((a[ch][0] != -1) && (a[ch][1] != -1))
                ch = a[ch][1];
            for(i = ch + 1; i < MAX; i++) {
                if(a[i][0] == -1) {
                    a[i][0] = num;
                    a[ch][1] = i;
                    flag = 1;
                    break;
                }
            }
        }
        if(flag != 1) {
            if(ch == -1) {
                for(i = 0; i < key; i++) {
                    if(a[i][0] == -1) {
                        a[i][0] = num;
                        a[key][1] = i;
                        flag = 1;
                        break;
                    }
                }
            }
            else {
                while((a[ch][0] != -1) && (a[ch][1] != -1))
                    ch = a[ch][1];
                for(i = ch + 1; i < key; i++) {
                    if(a[i][0] == -1) {
                        a[i][0] = num;
                        a[ch][1] = i;
                        flag = 1;
                        break;
                    }
                }
            }
        }
    }
}

void WO_chain::display() {
    cout << "\n The Hash Table is...\n";
    for(int i = 0; i < MAX; i++)
        cout << "\n  " << i << " " << a[i][0] << " " << a[i][1];
}

int main() {
    int num, key, i;
    int n;
    WO_chain h;
    cout << "\nChaining Without Replacement";
    cout << "\n Enter total keys to be inserted :";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "\n Enter The Number";
        cin >> num;
        key = h.create(num);
        h.chain(key, num);
    }
    h.display();
    return 0;
}

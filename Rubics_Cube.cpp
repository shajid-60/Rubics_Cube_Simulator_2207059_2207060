#include<bits/stdc++.h>
using namespace std;

struct Cube {
    char F[2][2], B[2][2], L[2][2], R[2][2], U[2][2], D[2][2];

    Cube()
    {
         fillFace(F,'W');
     fillFace(B,'G'); fillFace(L,'R');
      fillFace(R,'B'); 
        
    fillFace(U,'O'); fillFace(D,'Y');
    }

    void fillFace(char f[2][2], char c)
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                f[i][j]=c;
    }

    void moveUu() 
    {
        char t0=F[0][1],
    t1=F[1][1];
        F[0][1]=D[0][1]; 
    F[1][1]=D[1][1];
    D[0][1]=B[1][0];   D[1][1]=B[0][0];
    B[1][0]=U[0][1];
        
B[0][0]=U[1][1];
        U[0][1]=t0; U[1][1]=t1;
    }

    void moveDd() 
    {
        char t0=F[0][1],
        t1=F[1][1];
        F[0][1]=U[0][1]; 
        F[1][1]=U[1][1];
        U[0][1]=B[1][0]; 
    U[1][1]=B[0][0];
        B[1][0]=D[0][1];
    B[0][0]=D[1][1];
        D[0][1]=t0;
    D[1][1]=t1;
    }

    void moveRr() {
        char t0=F[1][0],
    t1=F[1][1];
        F[1][0]=L[1][0];
    F[1][1]=L[1][1];
        L[1][0]=B[0][1];
    L[1][1]=B[0][0];
        B[0][1]=R[1][0];
        
        B[0][0]=R[1][1];
        R[1][0]=t0; R[1][1]=t1;
    }

    void moveLl() 
    {
        char t0=F[1][0],
        
    t1=F[1][1];
        F[1][0]=R[1][0];
        
    F[1][1]=R[1][1];
        R[1][0]=B[0][1];   R[1][1]=B[0][0];
        B[0][1]=L[1][0]; B[0][0]=L[1][1];
        L[1][0]=t0; 
    L[1][1]=t1;
    }

    void rotateU() { swap(F,D); swap(U,F); swap(B,U); }
    void rotateD() { swap(F,U); swap(U,B); swap(B,D); }
    void rotateR() { swap(F,L); swap(L,B); swap(B,R); }
    void rotateL() { swap(F,R); swap(R,B); swap(B,L); }

    void printFace(char f[2][2], string name) 
    {
        cout<<name<<":\n";
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++) cout<<f[i][j]<<" ";
            cout<<"\n";
        }
    }

    void printCube() 
    {
        printFace(F,"Front");
 printFace(B,"Back"); printFace(L,"Left");
 printFace(R,"Right");
     printFace(U,"Up");
        printFace(D,"Down");
        cout<<endl;
    }
};

int main() 
{
    Cube c;
    int n;
    cin >> n;

    while(n--) 
        {
        int type;
        char ch;
        cin >> type >> ch;

        ch = tolower(ch);

        if(type == 1) 
        {
            if(ch=='u') c.moveUu();
            else if(ch=='d') c.moveDd();

     else if(ch=='r') c.moveRr();
            else if(ch=='l') c.moveLl();
        }
        else if(type == 2) 
        {
            if(ch=='u') c.rotateU();
            else if(ch=='d') c.rotateD();
    else if(ch=='r') c.rotateR();
            else if(ch=='l') c.rotateL();
        }

        c.printCube();
    }
    return 0;
}

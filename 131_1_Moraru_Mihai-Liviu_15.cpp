#include <iostream>

using namespace std;

class matrice{

private:
    int row, col;
    double** matrix;

public:
    matrice(double, int, int);
    matrice(int,int);
    matrice();
    ~matrice();
    matrice(const matrice&);

    int get_row()const;
    int get_col()const;
    double get_elem(int,int)const;

    void set_row(int);
    void set_col(int);
    void set_elem(double,int,int);

    void citire();
    void afisare();
    matrice operator =(const matrice&);

    void update(double, int, int);

    friend matrice operator +(matrice const&, matrice const&);
    friend matrice operator -(matrice const&, matrice const&);
    friend matrice operator *(matrice const&, matrice const&);
    friend bool operator ==(matrice const&, matrice const&);

    friend int nrlinii(matrice const&);
    friend int nrcoloane(matrice const&);
    friend int nrelemente(matrice const&);

};

matrice::matrice(double value,int n, int m)
{
    this->row=n;
    this->col=m;
    matrix=new double*[row];
    for(int i=0;i<row;i++)
        matrix[i]=new double[col];
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            matrix[i][j]=value;
}

matrice::matrice(int n, int m)
{
    this->row=n;
    this->col=m;
    matrix=new double*[row];
    for(int i=0;i<row;i++)
        matrix[i]=new double[col];
    double value = 0;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            matrix[i][j]=value;
}

matrice::matrice()
{
    this->row=100;
    this->col=100;
    matrix=new double*[row];
    for(int i=0; i<row; i++)
        matrix[i]=new double[col];
    double value = 0;
    for(int i=0; i<row; i++)
        for(int j=0;j<col;j++)
            matrix[i][j]=value;
}

matrice::~matrice()
{
    for(int i=0;i<row;i++)
        delete [] matrix[i];
    delete [] matrix;
}

matrice::matrice(const matrice& old)
{
    this->row=old.row;
    this->col=old.col;
    matrix=new double*[row];
    for(int i=0; i<row; i++)
        matrix[i]=new double[col];
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            matrix[i][j]=old.matrix[i][j];
}

int matrice::get_row()const{return row;}
int matrice::get_col()const{return col;}
double matrice::get_elem(int x,int y)const{return matrix[x][y];}
void matrice::set_row(int x){row=x;}
void matrice::set_col(int x){col=x;}
void matrice::set_elem(double x,int a,int b){matrix[a][b]=x;}

matrice matrice::operator = (const matrice &a)
{

    if(this==&a) return *this;
    for(int i=0; i<row; i++)
        delete []matrix[i];
    delete []matrix;
    row=a.row;
    col=a.col;
    matrix=new double*[row];
    for(int i=0; i<row; i++)
        matrix[i]=new double[col];
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
          matrix[i][j]=a.matrix[i][j];
    return *this;

}

void matrice::update(double c, int x, int y)
{
    this->row=x;
    this->col=y;
    matrix=new double*[row];
    for(int i=0;i<row;i++)
        matrix[i]=new double[col];
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            matrix[i][j]=c;
}

matrice operator +(matrice const &a, matrice const &b)
{
    int x1 = a.row;
    int x2 = b.row;
    int y1 = a.col;
    int y2 = b.col;
    matrice rezultat(x1,y1);

    if (x1!=x2 || y1!=y2)
        cout<<"Matricile nu pot fi adunate."<<endl;
    else
        for(int i=0; i<x1; i++)
            for(int j=0; j<y1; j++)
                   rezultat.matrix[i][j]=a.matrix[i][j]+b.matrix[i][j];

    return rezultat;

}

matrice operator -(matrice const &a, matrice const &b)
{
    int x1 = a.row;
    int x2 = b.row;
    int y1 = a.col;
    int y2 = b.col;
    matrice rezultat(x1,y1);

    if (x1!=x2 || y1!=y2)
        cout<<"Matricile nu pot fi scazute."<<endl;
    else
        for(int i=0; i<x1; i++)
            for(int j=0; j<y1; j++)
                   rezultat.matrix[i][j]=a.matrix[i][j]-b.matrix[i][j];

    return rezultat;

}

matrice operator *(matrice const &a, matrice const &b)
{
    int x1 = a.row;
    int x2 = b.row;
    int y1 = a.col;
    int y2 = b.col;
    matrice rezultat(x1,y2);

    if (y1!=x2)
        cout<<"Matricile nu pot fi inmultite"<<endl;
    else
        for(int i=0; i<x1; i++)
            for(int j=0; j<y2; j++)
            {
                for(int k=0;k<y1;k++)
                   rezultat.matrix[i][j]+=a.matrix[i][k]*b.matrix[k][j];
            }
    return rezultat;

}

bool operator ==(matrice const &a, matrice const &b)
{
    int x1 = a.row;
    int x2 = b.row;
    int y1 = a.col;
    int y2 = b.col;

    if (x1!=x2 || y1!=y2)
    {
        cout<<"Matricile nu pot fi comparate."<<endl;
        return 0;
    }
    else
        {
        for (int i=0; i<x1; i++)
            for(int j=0; j<y1;j++)
            {
                if (a.matrix[i][j]!=b.matrix[i][j]) return 0;
            }
        return 1;
        }
}

int nrlinii(matrice const&a)
{
    return a.row;
}

int nrcoloane(matrice const&a)
{
    return a.col;
}

int nrelemente(matrice const&a)
{
    return a.row*a.col;
}

void matrice::citire()
{
    cout<<"Introduceti numarul de linii ale matricei: "<<endl;
    cin>>row;
    cout<<"Introduceti numarul de coloane ale matricei: "<<endl;
    cin>>col;
    cout<<"Introduceti elementele matricei: "<<endl;
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            {
             cin>>matrix[i][j];
            }
}


void matrice::afisare()
{
    cout<<"Numarul de linii: "<<row<<endl;
    cout<<"Numarul de coloane: "<<col<<endl;

    cout<<"Elementele matricei: "<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }

}
///Am incercat dar chiar nu am idee cum sa fac un program
///pentru a gasi inversa unei matrici.
/*
int determinant(const matrice&a)
{
    int x=a.get_row();
    int y=a.get_col();
    double d=0;
    if (x!=y)
    {
        cout<<"Nu exista determinant."<<endl;
        return d;
    }
    else
        if (x==1 && y==1)
        {
            cout<<"Matrice grad 1"<<endl;
            d=a.get_elem(x,y);
            return d;

        }
    else
    {
        for(int i=0; i<x; i++)
            for(int j=0; j<x; j++)
                if (i==j)
                {
                    d+=a.get_elem(i,j);
                }
        int i=0;
        int j=x-1;
        while (i<x && j>=0)
        {
            d-=a.get_elem(i,j);
            i++;
            j--;
        }
    return d;
    }
}

matrice transpusa(const matrice&a)
{
    int x=a.get_row();
    int y=a.get_col();
    matrice A=a;
    if (x!=y)
    {
        cout<<"Nu se poate face transpusa;"<<endl;
        return a;
    }
    for (int i=0; i<x; i++)
        for(int j=0; j<x; j++)
            A.set_elem(a.get_elem(i,j),j,i);
    return A;
}

matrice adjuncta(const matrice&a)
{
    int x=a.get_row();
    int y=a.get_col();
    matrice A;
    for (int i=0; i<x; i++)
        for(int j=0; j<x; j++)
            A.set_elem(determinant())
}

*/
int main()
{

    matrice N(2,2,3);
    matrice M=N;
    N.afisare();
    M.afisare();

    matrice K;
    K.citire();
    K.afisare();

    N.update(3,2,3);
    N.afisare();

    matrice G;
    G=N+M;

    cout<<"Suma matricilor: "<<endl;
    G.afisare();

    G=M-N;
    cout<<"Diferenta matricilor: "<<endl;
    G.afisare();

    G=M*N;
    cout<<"Produsul matricilor: "<<endl;
    G.afisare();

    if(M==N) cout<<"Matrici egale";




    return 0;
}

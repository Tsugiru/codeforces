#include<iostream>
using namespace std;

struct node{
    double x, y;
    node *prev, *next;
};

struct dList{
    node*head;
    node*tail;
};

void initializelist(dList &l){
    l.head = NULL;
    l.tail = NULL;
}

void initializenode(node *n){
    n->next = NULL;
    n->prev = NULL;
}

bool isEmpty(dList l)
{
    return l.head == NULL || l.tail == NULL;
}


void tabletolist(dList &l, double t[][2], int n)
{
    initializelist(l);
    /*l.head = NULL;
    l.tail = NULL;*/
    node*tmp1 = new node;
    tmp1->x = t[0][0];
    tmp1->y = t[0][1];
    tmp1->next = NULL;
    tmp1->prev = NULL;
    l.head = tmp1;
    //l.tail = tmp1;
    node*cur = new node;
    cur = l.head;
    for (int i = 1; i < n; i++)
    {
        node*tmp = new node;
        if (tmp == NULL)
            exit(1);
        tmp->x = t[i][0];
        tmp->y = t[i][1];
        tmp->prev = cur;
        tmp->next = NULL;
        cur->next = tmp;
        l.tail = tmp;
        //cur->next = l.tail;
        cur = cur->next;
    }
}

/*void aff(dList l)
{
node *cur = l.head;
while (cur != NULL)
{
cout << cur->x << cur->y << " ";
cur = cur->next;

}

}*/

void coeff(dList l, int n, double(*A)[3])//liste comme argument avec n le nbr de noeuds ds la liste et le tableau contenant A, B et C de l'equation
{

    node*cur = new node;
    initializenode(cur);
    cur = l.head;


    for (int i = 0; i <n - 1; i++)
    {
        A[i][0] = (cur->y - cur->next->y);
        A[i][1] = cur->next->x - cur->x;
        A[i][2] = (cur->x)*(cur->next->y) - (cur->next->x)*(cur->y);
        cur = cur->next;


        //cout << A[i][0] << "  " << A[i][1] << "   " << A[i][2] << endl;
    }

}


node* intersection(double R[][3], int n, dList l1, double Q[][3], int m, dList l2)
{
    double p, s, k;
    node *cur = new node;

    node *cur1 = new node;
    node *cur2 = new node;

    cur1 = l1.head;
    cur2 = l2.head;


    for (int i = 0; i < n-1; i++){
        cur2 = l2.head;
        for (int j = 0; j < m-1; j++)
        {
            p = Q[j][0] * R[i][1] - R[i][0] * Q[j][1];
            if (p != 0){
                //cout << "Les segments de lignes sont paralleles ou identiques.";
                s = Q[j][1] * R[i][2] - R[i][1] * Q[j][2];
                k = R[i][0] * Q[j][2] - Q[j][0] * R[i][2];
                cur->x = s / p;
                cur->y = k / p;
            }
            //cout <<"("<< cur->x << ";" << cur->y << ")";

        //il faut verifier si le point d'inter des 2 DROITES appartiens aux 2 SEGMENTS

            if (cur->x >= cur1->x && cur->x <= cur1->next->x){
                if (cur->x >= cur2->x && cur->x <= cur2->next->x){
                    cout << "l mazbout houwe.." << "(" << cur->x << ";" << cur->y << ")";
                    return cur;
                }
            }



            cur2 = cur2->next;
        }
        cur1 = cur1->next;
    }
    cout << "mafi pint d'inter";
    return NULL;
}


void interpolation(node *point1,node* point2,node* point3 ,node *P){
    double a, b, c;
    a = point1->y - point2->y;
    b = point2->x - point1->x;
    c = (point1->x)*(point2->y) - (point2->x)*(point1->y);

    double x = point3->x;
    double y = (-a*x - c) / b;
    P->x = x;
    P->y = y;
}


void somme(dList l3, dList l4, dList &l5){
    node *cur3 = new node;
    node *cur4 = new node;
    node *cur5 = new node;
    initializenode(cur3);
    initializenode(cur4);
    initializenode(cur5);
    cur3 = l3.head;
    cur4 = l4.head;
    cur5 = l5.head;
    while (cur3 != NULL || cur4 != NULL){
        if (cur3->x == cur4->x){
            cur5->x = cur3->x;
            cur5->y = cur3->y + cur4->y;
            cur5 = cur5->next;
            cur3 = cur3->next;
            cur4 = cur4->next;
        }
        if (cur3->x < cur4->x){
            cur5->x = cur3->x;
            node*p = new node;
            initializenode(p);
            interpolation(cur4, cur4->prev, cur3, p);
            cur5->x = p->x;
            cur5->y = p->y;
            cur3 = cur3->next;
            cur5 = cur5->next;    
        }
        if (cur3->x > cur4->x){
            cur5->x = cur4->x;
            node*p = new node;
            initializenode(p);
            interpolation(cur3, cur3->prev, cur4, p);
            cur5->x = p->x;
            cur5->y = p->y;
            cur4 = cur4->next;
            cur5 = cur5->next;
        }
    }
}



int main(){
/*    dList l1;
    dList l2;
    int N = 7;  //nbr de points bl awwle
    int M = 7;  //nbr de points bi tene wehde

    //cin >> N;

    double(*t1)[2];
    t1 = new double[N][2];

    double(*t2)[2];
    t2 = new double[N][2];

    cout << "Inserer les points de la 1ere courbe.\n";
    for (int i = 0; i < N; i++)
    for (int j = 0; j < 2; j++)
        cin >> t1[i][j];

    cout << "Inserer les points de la 2eme courbe.\n";
    for (int i = 0; i < N; i++)
    for (int j = 0; j < 2; j++)
        cin >> t2[i][j];

    tabletolist(l1, t1, N);
    tabletolist(l2, t2, N);

    double(*Q)[3];
    Q = new double[N - 1][3];
    double(*R)[3];
    R = new double[N - 1][3];

    coeff(l1, N, Q);
    coeff(l2, N, R);
    intersection(R, N, l1, Q, M, l2);
    //aff(l);

    */


    /*dList l3, l4, l5;
    initializelist(l3);
    initializelist(l4);
    initializelist(l5);

    int e = 3;
    int f = 3;

    double(*E)[2];
    E = new double[e][2];
    double(*F)[2];
    F = new double[f][2];

    tabletolist(l3, E, e);
    tabletolist(l4, F, f);*/

    tabletolist(l3, t3, N);
    tabletolist(l4, t4, N);
    somme(l3, l4, l5);
    node *cur = new node;
    initializenode(cur);
    cur = l5.head;
    while (cur != NULL)
    {
        cout << "\n x " << cur->x << " ";
        cur = cur->next;
    }
    cur = l5.head;

    while (cur != NULL)
    {
        cout << "\n y " << cur->y << " ";
        cur = cur->next;
    }

    cout << "okk";
    system("pause");
    return 0;
}
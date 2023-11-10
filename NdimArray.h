#ifndef NDIMARRAY_H_INCLUDED
#define NDIMARRAY_H_INCLUDED

#include <iostream>
#include <math.h>


using namespace std;
class NdimArray{
private:
    int len;
    int dim;
    float *A;
    float TotalSum;
    int arraySize;

    double log2(double x){
        return log(x)/log(2);

    }

public:
    NdimArray(int _size,int n){
        len = _size;
        dim = n;
        arraySize=1;
        TotalSum=0;

        for (int i=0;i<n;i++){
                arraySize*=len;
        }

        A=new float [arraySize];
        for (int i=0;i<arraySize;i++){
            A[i]=0;
        }

    }
    ~NdimArray(){
        delete A;
    }

    float CalcEntropy(){
        float p, H;
        for (int i=0;i<arraySize;i++){
            p=A[i]/TotalSum;
            H+=p*log2(p);
        }
        return -H;
    }

    void add(int i){
        A[i]++;
        TotalSum++;
    }
    void add(int i,int j){
        A[i*len+j]++;
        TotalSum++;
    }
    void add(int i,int j,int k){
        int tmp=i;
        tmp=tmp*len+j;
        tmp=tmp*len+k;

        A[tmp]++;
        TotalSum++;
    }
    void add(int i,int j,int k,int l){
        int tmp=i;
        tmp=tmp*len+j;
        tmp=tmp*len+k;
        tmp=tmp*len+l;

        A[tmp]++;
        TotalSum++;
    }
    void add(int i,int j,int k,int l,int m){
        int tmp=i;
        tmp=tmp*len+j;
        tmp=tmp*len+k;
        tmp=tmp*len+l;
        tmp=tmp*len+m;

        A[tmp]++;
        TotalSum++;
    }
    float get(int i){
        if (dim!=1) throw 1;

        return A[i];
    }
    float get(int i,int j){
        if (dim!=2) throw 1;

        return A[i*len+j];
    }
    float get(int i,int j,int k){
        if (dim!=3) throw 1;

        int tmp=i;
        tmp=tmp*len+j;
        tmp=tmp*len+k;

        return A[tmp];
    }
    float get(int i,int j,int k,int l){
        if (dim!=4) throw 1;

        int tmp=i;
        tmp=tmp*len+j;
        tmp=tmp*len+k;
        tmp=tmp*len+l;

        return A[tmp];
    }
    float get(int i,int j,int k,int l,int m){
        if (dim!=4) throw 1;

        int tmp=i;
        tmp=tmp*len+j;
        tmp=tmp*len+k;
        tmp=tmp*len+l;
        tmp=tmp*len+m;

        return A[tmp];
    }
};

#endif // NDIMARRAY_H_INCLUDED

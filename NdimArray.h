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
    void add(int *_A){
        int tmp=0;
        for (int i=0;i<dim;i++){
                tmp=tmp*len+_A[i];
        }
        A[tmp]++;
        TotalSum++;
    }
    int getDim(){
        return dim;
    }
    float get(int i){
        if ((i<0)||(i>=pow(len,dim)))throw 4;
        return A[i];
    }

};

#endif // NDIMARRAY_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <vector>

std::vector<char> myers(std::vector<char> list1, std::vector<char> list2, int count1=0, int count2=0) {
  int N = list1.size();
  int M = list2.size();
  int L = N+M;
  int Z = 2*std::min(N,M)+2;

  std::cout << N << " " << M << std::endl;
  if(N>0 && M>0) {
    int W = N-M;
    std::vector<int> G(Z, 0);
    std::vector<int> P(Z, 0);

    for(int i=0; i< (L/2 + (L%2!=0))+1; i++) {
      for(int j=0; j<2; j++) {
	std::vector<int> C, D;
	int O, M1;
	if(j == 0) {
	  C = G;
	  D = P;
	  O = 1;
	  M1 = 1;
	}
	else {
	  C = P;
	  D = G;
	  O = 0;
	  M = -1;
	}
	for(int k= -(i-2*std::max(0, i-M)); k< i-2*std::max(0, i-N)+1; k+=2) {
	  std::cout << "here\n";
	  int A;
	  if(k==-i || (k!=i && C[(k-1)%Z]<C[(k+1)%Z])) {
	    A=C[(k+1)%Z];
	  }
	  else {
	    A=C[(k-1)%Z]+1;
	  }
	  int B=A-k;
	  int S=A;
	  int T=B;
	  while(A<N && B<M && list1[(1-O)*N+M1*A+(O-1)]==list2[(1-O)*M+M1*B+(O-1)]){
	    A=A+1;
	    B=B+1;
	  }
	  C[k%Z]=A;
	  int Z1=-(k-W);
	  std::cout << "L: " << L << " Z1: " << Z1 << " i: " << i << std::endl;
	  std::cout << "C: " << C[k%Z] << " D: " << D[Z1%Z] << " N: " << N << std::endl;
	  if(L%2==O && Z1>=-(i-O) && Z1<=i-O && C[k%Z]+D[Z1%Z]>=N) {
	    int D1, X, Y, U, V;
	    if(O==1) {
	      D1=2*i-1;
	      X=S;
	      Y=T;
	      U=A;
	      V=B;
	    }
	    else {
	      D1=2*i;
	      X=N-A;
	      Y=M-B;
	      U=N-S;
	      V=M-T;
	    }
	    std::cout << "here1";
	    if(D1>1 || (X != U && Y != V)) {
	      std::vector<char> temp1(list1.begin(), list1.begin()+X);
	      std::vector<char> temp2(list2.begin(), list2.begin()+Y);
	      std::vector<char> temp3 = myers(temp1, temp2, count1, count2);
	      std::vector<char> temp4(list1.begin()+U, list1.begin()+N);
	      std::vector<char> temp5(list2.begin()+V, list2.begin()+M);
	      std::vector<char> temp6 = myers(temp4, temp5, count1+U, count2+V);
	      temp3.insert(temp3.end(), temp6.begin(), temp6.end());
	      return temp3;
	    }
	    else if(M>N) {
	      std::vector<char> temp1;
	      std::vector<char> temp2(list2.begin()+N, list2.begin()+M);
	      return myers(temp1, temp2, count1+N, count2+M);
	    }
	    else if(M<N) {
	      std::vector<char> temp1(list1.begin()+M, list2.begin()+N);
	      std::vector<char> temp2;
	      return myers(temp1, temp2, count1+M, count2+N);
	    }
	    else {
	      std::vector<char> temp1;
	      return temp1;
	    }
	  }
	}
      }
    }
  }
  std::vector<char> temp1;
  return temp1;
}

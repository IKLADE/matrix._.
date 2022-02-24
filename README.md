*README FILE
  1.default matrix 3x3
  2.can be invoked using matrix1 m1(2,2),m2,m3(4,4);
  3.addition(m3=m1+m2)
  4.subtraction(m3=m1-m2)
  5.multiplication(m3=m1*m2)
  6.scalar multiplication(m3=m1*5)
  7.addition compatibility(addcomp(m1,m2) ----- returns boolean value)
  8.multiplication compatibility(multcomp(m1,m2) ----- returns boolean value)
  9.input(cin>>m1)
  10.output(cout<<m1)
  11.transpose(m2=transpose(m1))
  12.cofactor(m2=cofactor(m1,0,0)  ----- returns a cofactor matrix of element (0,0) of m1)
  13.determinant(x=determinant(m1) ----- returns a float value)
  14.adjoint(m2=adjoint(m1) ----- transpose of cofactor value of every element in matrix,the cofactor value wll have alternating signs(+ve,-ve))
  15.inverse(m2=inverse(m1) ----- inverse(m1)=adjoint(m1)/det(m1))

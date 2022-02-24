*README FILE
  default matrix 3x3
  can be invoked using matrix1 m1(2,2),m2,m3(4,4);
  addition(m3=m1+m2)
  subtraction(m3=m1-m2)
  multiplication(m3=m1*m2)
  scalar multiplication(m3=m1*5)
  addition compatibility(addcomp(m1,m2) ----- returns boolean value)
  multiplication compatibility(multcomp(m1,m2) ----- returns boolean value)
  input(cin>>m1)
  output(cout<<m1)
  transpose(m2=transpose(m1))
  cofactor(m2=cofactor(m1,0,0)  ----- returns a cofactor matrix of element (0,0) of m1)
  determinant(x=determinant(m1) ----- returns a float value)
  adjoint(m2=adjoint(m1) ----- transpose of cofactor value of every element in matrix,the cofactor value wll have alternating signs(+ve,-ve))
  inverse(m2=inverse(m1) ----- inverse(m1)=adjoint(m1)/det(m1))

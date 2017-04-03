def Linear_Eq_Solver(A,x,n):

	sum = 0.0
	for i in range(n):
		x.append(0)

	for j in range(n):
		for i in range(n):
			if(i>j):
				c = A[i][j]/A[j][j];
				for k in range(1,n+1):
					A[i][k]=A[i][k]-(c*A[j][k])
	
	x[n-1] =(A[n-1][n]/A[n-1][n-1])
		
	for i in range(n-2,-1,-1):
		sum = 0
		for j in range(i+1,n):
			sum = sum + (A[i][j]*x[j])
		x[i] = (A[i][n]-sum)/A[i][i]
	
	for i in range(len(x)):
		x[i] = round(x[i],4)
	

def power_sum(X,n):
	sum = 0
	for i in X:
		sum = sum + pow(i,n)
	return sum

def product_sum(X,x_pow,Y):
	sum = 0
	for i in range(len(X)):
		tmp = pow(X[i],x_pow)*Y[i]
		sum = sum + tmp
	return sum

def Linear_Fit(X,Y):
	
	x_sum = power_sum(X,1)
	x_2_sum = power_sum(X,2)	
	y_sum = power_sum(Y,1)
	xy_sum = product_sum(X,1,Y)
	
	

	a = ((9*xy_sum)-(x_sum*y_sum))/((9*x_2_sum)-(x_sum*x_sum));
	b = ((y_sum*x_2_sum)-(x_sum*xy_sum))/((9*x_2_sum)-(x_sum*x_sum));
	
	a = round(a,4)
	b = round(b,4)

	print("\n\nLinear Equation : ");
	print("\ty = %s + %sx"%(b,a))
	print("\nValues Obtained from above equation are : \n")

	for i in range(9):
		print("Y(%s) = %s"%(X[i],(b+(X[i]*a))))

def Quadratic_Fit(X,Y):

	A=[]
	x=[]
	
	x_sum = power_sum(X,1)
	x_2_sum = power_sum(X,2)
	x_3_sum = power_sum(X,3)
	x_4_sum = power_sum(X,4)
	y_sum = power_sum(Y,1)
	xy_sum = product_sum(X,1,Y)
	x2y_sum = product_sum(X,2,Y)

	A= [[9,x_sum,x_2_sum,y_sum],[x_sum,x_2_sum,x_3_sum,xy_sum],[x_2_sum,x_3_sum,x_4_sum,x2y_sum]]
	
	
	Linear_Eq_Solver(A,x,3)
	
	print("\n\nQuadratic Equation is : ")
	print("\ty = %s + %sx + %sx2"%(x[0],x[1],x[2]))
	print("\n")
	print("Values Obtained from above equation are : \n")
	
	for i in range(9):
		print("Y(%s) = %s"%(X[i],(x[0]+(x[1]*X[i])+(x[2]*X[i]*X[i]))))

def Cubic_Fit(X,Y):

	A=[]
	x=[]
	
	x_sum = power_sum(X,1)
	x_2_sum = power_sum(X,2)
	x_3_sum = power_sum(X,3)
	x_4_sum = power_sum(X,4)
	x_5_sum = power_sum(X,5)
	x_6_sum = power_sum(X,6)
	y_sum = power_sum(Y,1)
	xy_sum = product_sum(X,1,Y)
	x2y_sum = product_sum(X,2,Y)
	x3y_sum = product_sum(X,3,Y)

	A= [[9,x_sum,x_2_sum,x_3_sum,y_sum],[x_sum,x_2_sum,x_3_sum,x_4_sum,xy_sum],[x_2_sum,x_3_sum,x_4_sum,x_5_sum,x2y_sum],[x_3_sum,x_4_sum,x_5_sum,x_6_sum,x3y_sum]]
	
	
	Linear_Eq_Solver(A,x,4)
	
	print("\n\nCubic Equation is : ")
	print("\ty = %s + %sx + %sx2 + %sx3"%(x[0],x[1],x[2],x[3]))
	print("\n")
	print("Values Obtained from above equation are : \n")

	for i in range(9):
		print("Y(%s) = %s"%(X[i],(x[0]+(x[1]*X[i])+(x[2]*X[i]*X[i])+(x[3]*X[i]*X[i]*X[i]))))

print("\n\t\t\tLeast Square Fit ")
print("\n1. Linear Fit")
print("\n2. Quadratic Fit")
print("\n3. Cubic Fit")

ch = input('\nEnter your choice : ')

X = (-4,-3,-2,-1,0,1,2,3,4)
Y = (0,0,0,0,1,0,0,0,0)

if ch=='1':
	Linear_Fit(X,Y)
elif ch=='2':
	Quadratic_Fit(X,Y)
elif ch=='3':
	Cubic_Fit(X,Y)

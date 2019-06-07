def find_median(A, ai, af, B, bi, bf, k):
    m, n = af - ai, bf - bi
    if n == 0: return A[ai + k - 1]
    if k == 1: return min(A[ai], B[bi])

    b_m = int(k/2)
    a_m = k - b_m
    if A[ai + a_m - 1] < B[bi + b_m - 1]:
        return find_median(A, ai + a_m, af, B, bi, bi + b_m, k - a_m)
    else:
        return find_median(A, ai, ai + a_m, B, bi + b_m, bf, k - b_m)


print("qual o tamanho de cada um dos bancos?")
n = int(input())
m = 2*n
AB = []
print("agora digite cada um dos 2*n numeros armazenados nos dois bancos:")
for i in range(0, m):
    aux = int(input())
    AB.append(aux)
AB.sort()
A = AB[0:n]
B = AB[n:]

print("the median is :"+str(find_median(A, 0, n, B, 0, n, int((m + 1)/2))))
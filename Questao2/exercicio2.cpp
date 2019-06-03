#include <bits/stdc++.h> 
#define debug(x) cerr << #x << ": " << x << endl;
#define debug_array(x, _size) cerr << #x << ":"; for(int i=0; i<_size; ++i){cerr << " " << x[i];} cerr << endl;
#define debug_matriz(x, _size_i, _size_j) cerr << #x << endl; for(int i=0; i<_size_i; ++i){for(int j=0; j<_size_j; ++j){cerr << setw(2) << x[i][j] << " ";} cerr << endl;};

using namespace std; 
  
int getInvCount(int arr[], int n) 
{ 
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] > 2*arr[j]) 
                inv_count++; 
  
    return inv_count; 
} 
 
int merge(int elementos[], int inicio, int meio, int fim){
	vector<int> merge_elementos;
	int inversoes = 0, i = inicio, j = meio;
	//debug(inicio);
	//debug(meio);
	//debug(fim);
	for(; i <= meio-1 && j<=fim;){
		//debug(i);
		//debug(j);
		//debug(elementos[i])
		//debug(elementos[j])
		if(elementos[i] > 2*elementos[j]){// && elementos[i] != 2*elementos[j]){
			if(elementos[i] > 2*elementos[j])
				inversoes += meio-i;

			merge_elementos.push_back(elementos[j]);
			j++;

		}else{
			merge_elementos.push_back(elementos[i]);
			i++;
		}
		//debug(inversoes);
		//debug_array(merge_elementos, int(merge_elementos.size()));
	}

	for(; i <= meio - 1; ++i){
        merge_elementos.push_back(elementos[i]); 
	}
  
    for(; j <= fim; ++j)  
        merge_elementos.push_back(elementos[j]);  
  	
  	//debug_array(merge_elementos, int(merge_elementos.size()));
    i = inicio;
    for(int elemento : merge_elementos){
    	elementos[i] = elemento;
    	i++;
    }
    //debug_array(elementos, fim+1);
	return inversoes;
}

int getInvCountMerge(int elementos[], int inicio, int fim){
	int meio, inversoes = 0;
	//debug(inicio);
	//debug(fim);
	if(fim > inicio){
		meio = (fim+inicio)/2;
		//debug(meio);
		inversoes = getInvCountMerge(elementos, inicio, meio);
		inversoes += getInvCountMerge(elementos, meio+1, fim);
		inversoes += merge(elementos, inicio, meio+1, fim);
	}
	//debug(inversoes);
	return inversoes;
}

int main() 
{ 
    int N;
    cerr << "Insira o tamanho da sequência de números [0,10000]: ";
    cin >> N;
    int array[100000];
    set<int> dobro;
 	cerr << "Insira os números desejados:\n";
    set<int> elementos;
    for(int i=0; i<N; ++i){
    	cerr << "Array[" << i+1 << "] = ";
    	cin >> array[i];
    	elementos.insert(array[i]);
    }
    cerr << endl;
    int qnt_dobro = 0;
    for(int i = N-1; i>=0; --i){
    	//debug(i);
    	if(elementos.count(array[i]))
    		elementos.erase(array[i]);

    	if(elementos.count(array[i]*2))
    		qnt_dobro++;
    }

    cout << "~ Algorítmo O(n²) ~\n";
    cout << "O número de inversões é " << getInvCount(array, N) << endl; 
    cout << endl;
    cout << "~ Algorítmo O(nlog(n)) ~\n";
    cout << "O número de inversões é " << getInvCountMerge(array, 0, N-1) - qnt_dobro<< endl;
    return 0; 
} 

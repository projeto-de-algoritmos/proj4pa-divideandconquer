#include <bits/stdc++.h> 
#define debug(x) cerr << #x << ": " << x << endl;
#define debug_array(x, _size) cerr << #x << ":"; for(int i=0; i<_size; ++i){cerr << " " << x[i];} cerr << endl;
#define debug_array_cartao(x, _size) cerr << #x << ":"; for(int i=0; i<_size; ++i){cerr << " " << x[i].conta << ":" << x[i].quantidade ;} cerr << endl;
#define debug_matriz(x, _size_i, _size_j) cerr << #x << endl; for(int i=0; i<_size_i; ++i){for(int j=0; j<_size_j; ++j){cerr << setw(2) << x[i][j] << " ";} cerr << endl;};

using namespace std; 

class Cartao{
public:
	int conta;
	int quantidade = 1;

	Cartao(int conta){
		this->conta = conta;
	}
};

vector<Cartao> compara_cartoes(vector<Cartao> sequencia_de_cartoes);

int main(){

	int N;
	cerr << "Insira a quantidade de cartões que deseja verificar: ";
	queue<Cartao> cartoes;
	cin >> N;
	for(int i=0; i<N; ++i){
		int conta;
		cerr << "Insira a conta do cartão nº" << i+1 << ": ";
		cin >> conta;
		cartoes.push(Cartao(conta));
	}

	int tamanho_atual = cartoes.size(), tamanho_anterior = 0;
	//debug(tamanho_atual);

	while(tamanho_atual!=tamanho_anterior){
		vector<Cartao> sequencia_de_cartoes;
		for(int i=0; i < tamanho_atual; ++i){
			sequencia_de_cartoes.push_back(cartoes.front());
			cartoes.pop();

			if(sequencia_de_cartoes.size() == 5 ||
				i+1 == tamanho_atual){
				//debug_array_cartao(sequencia_de_cartoes, int(sequencia_de_cartoes.size()));
				sequencia_de_cartoes = compara_cartoes(sequencia_de_cartoes);
				//debug_array_cartao(sequencia_de_cartoes, int(sequencia_de_cartoes.size()));
				for(int j=0; j<int(sequencia_de_cartoes.size()); ++j){
					if(sequencia_de_cartoes[j].quantidade!= 0){
						//debug(sequencia_de_cartoes[j].conta);
						//debug(sequencia_de_cartoes[j].quantidade);
						cartoes.push(sequencia_de_cartoes[j]);
					}
				}
				sequencia_de_cartoes.clear();
				//debug_array_cartao(sequencia_de_cartoes, int(sequencia_de_cartoes.size()));
			}
		}
		tamanho_anterior = tamanho_atual;
		tamanho_atual = cartoes.size();
		//debug(tamanho_anterior);
		//debug(tamanho_atual);
	}

	bool equals = false;
	tamanho_atual = cartoes.size();
	//debug(tamanho_atual);
	for(int i=0; i< tamanho_atual; ++i){
		Cartao cartao_atual = cartoes.front();
		cartoes.pop();
		//debug(cartao_atual.quantidade);
		if(cartao_atual.quantidade > N/2){
			equals = true;
			break;
		}
	}

	cout << (equals? "Há um conjunto com mais de " : 
		"Não existe um conjunto com mais de ") <<  N/2 << " cartões!" <<endl;

	return 0;
}

vector<Cartao> compara_cartoes(vector<Cartao> sequencia_de_cartoes){
	for(int i=0; i<int(sequencia_de_cartoes.size()); ++i){
		if(sequencia_de_cartoes[i].quantidade > 0){
			//debug(sequencia_de_cartoes[i].id);
			//debug(sequencia_de_cartoes[i].quantidade);
			for(int j=i+1; j<int(sequencia_de_cartoes.size()); ++j){
				if(sequencia_de_cartoes[i].conta == 
				   sequencia_de_cartoes[j].conta){
					//debug(sequencia_de_cartoes[j].id);
					//debug(sequencia_de_cartoes[j].quantidade);
					sequencia_de_cartoes[i].quantidade +=
					sequencia_de_cartoes[j].quantidade;
					sequencia_de_cartoes[j].quantidade = 0;
				}
			}
		}
	}
	return sequencia_de_cartoes;
}
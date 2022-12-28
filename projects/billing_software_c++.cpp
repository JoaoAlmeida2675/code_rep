#include <iostream>
#include <vector>
#include <string>
#include <sstream>	 // P/USAR NA TROCA DO TIPO DE DADOS NA COBERTURA
#include <ctime>
#include <stdlib.h>  // P/USAR SYSTEM("CLS") NO VOID CRIADO

using namespace std;


vector<string> tipoRecp {
	" ", "Copo", "Cone"
};

vector<string> tamRecp {
	" ", "Pequeno - 2 Ing / 2,50€", 
	"Médio - 3 Ing / 3,50€", 
	"Grande - 4 Ing / 4,20€"
};

vector<string> tipoSab {
	"", "Morango", "Chocolate", "Nata", "Baunilha",
	"Mel", "Stracciatella", "Menta", "Café",
	"Framboesa", "Manga", "Limão", "Avelã"
};

vector<string> coberturas {
	" ", "Oreo", "M&M´s",
	"Raspas de Chocolate",
	"Sprinkles Coloridos"
};

vector<double> prcTam { -1, 2.50, 3.50, 4.20 };

vector<double> prcIngext { 1.00 };


void clrscr() {  // LIMPAR ECRAN P/MOSTRAR FATURA
   system("cls");
}

		// INICIO

int main () {
	start1:
	
	cout << "*******************************" << endl;
	cout << "****** Gelataria Bom Mel ******" << endl;
	cout << "*******************************" << endl << endl;

		// TIPO RECIPIENTE
		
	double precoTotal;
	int opcRecp;
	while (true) {
		start2:
		
		int sabEsc;
		cout << "Escolha o Tipo de Recipiente:" << endl;
		for (int i = 1; i < tipoRecp.size(); ++i) {
			cout << i << " - " << tipoRecp[i] << endl;
		}
		cout << endl;
		cout << "Recipiente escohido - ";
		cin >> opcRecp;
		if (opcRecp >= 1 && opcRecp <= 2) {
			cout << tipoRecp[opcRecp] << endl << endl;
			break;
		}
		else {
			cout << "Volte a introduzir opcao" << endl << endl;
		}
	}
		// TAMANHO ESCOLHIDO
		
	int tamEsc;
	while (true) {
		cout << "Indique o tamanho:" << endl;
		for (int i = 1; i < tamRecp.size(); ++i) {
			cout << i << " - " << tamRecp[i] << endl;
		}
		cout << endl;
		cout << "Tamanho escolhido - ";
		cin >> tamEsc;
		if (tamEsc >= 1 && tamEsc <= 3) {
			cout << tamRecp[tamEsc] << endl << endl;
			break;
		}
		else {
			cout << "Volte a introduzir opcao" << endl << endl;
		}
	}
		// TIPOS TAMANHO

	cout << "Lista de ingredientes:" << endl << endl;
	for (int i = 1; i < tipoSab.size(); i++) {
		cout << i << " - " << tipoSab[i] << endl;
	}
	cout << endl;

	int numSabores = tamEsc + 1;
	int sabEsc;
	vector<string> sabEscs;
	for (int i = 0; i < numSabores; ++i) {
		cout << "Escolha ingrediente - ";
		cin >> sabEsc;
		if (sabEsc >= 1 && sabEsc <= 12) {
			sabEscs.push_back(tipoSab[sabEsc]);
			cout << tipoSab[sabEsc] << endl << endl;
		}
		else {
			cout << "Opcao incorrecta, introduza uma opcao válida" << endl;  
			i--;  // NAO VALIDA A OPCAO ENQUANTO NAO FOR A CORRETA, VOLTA SEMPRE A OPCAO ANTERIOR
		}
	}
		// TIPO COBERTURA

	cin.ignore(1000, '\n');
	int cobEsc;
	while (true) {
		cout << "Escolha um tipo de cobertura: (+ 1.00€)" << endl;
		cout << "(Se nao desejar cobertura prima Enter)" << endl;
		for (int i = 1; i < coberturas.size(); ++i) {
			cout << i << " - " << coberturas[i] << endl;
		}
		cout << endl;
		
		cout << "Cobertura desejada - ";
		string cobEscStr;
		getline(cin, cobEscStr);

		if (cobEscStr.length() == 0) {
			cobEsc = 0;
			cout << "Nao deseja cobertura" << endl;
			break;
		}
		else {
			stringstream ss(cobEscStr);
			ss >> cobEsc;
			if (cobEsc >= 1 && cobEsc <= 4) {
				cout << coberturas[cobEsc] << endl;
				break;
			}
			else {
				cout << "Volte a introduzir opcao" << endl;
			}
		}
	}
	cout << endl;

		// PEDE MAIS GELADOS IGUAIS OU NAO

	int	pedIdn;
	while (true) {
		cout << "(Se houver pedidos identicos, introduza o montante. Caso contrario introduza 0)" << endl;

		cout << "Introduza o montante de pedidos identicos: ";
		cin >> pedIdn;
		cout << endl;
		if (pedIdn >= 0) {
			cout << "Mais " << pedIdn << " extra." << endl;
			break;
		}
		else {
			cout << "Opcao incorrecta" << endl;
		}
	}
			// RESUMO PEDIDO & FATURA

	cout << endl;
	time_t rawtime;  //HORAS
	time (&rawtime);
	
	string opConf;

	cout << " Resumo do pedido:" << endl << endl;
	cout << " Recipiente ----> " << tipoRecp[opcRecp] << endl; //AVALIA E DA A OPCAO ESCOLHIDA P/USER
	cout << " Tamanho    ----> " << tamRecp[tamEsc] << endl;
	cout << " Cobertura  ----> " << coberturas[cobEsc] << endl;
	cout << " Qt Sabores ----> " << numSabores << endl;
	cout << " Sabores: " << endl;
	for (int i = 0; i < sabEscs.size(); i++) {
			cout << " ....... " << sabEscs[i] << endl;
		}
	cout << " Quantidade ----> " << pedIdn+1 << endl;
	precoTotal = prcTam[tamEsc] * (pedIdn+1);
	if (cobEsc >= 1) precoTotal = precoTotal + pedIdn + 1;
	cout << " Preço p/Gelado-> " << precoTotal/(pedIdn+1) << "€" << endl;
	cout << " Total      ----> " << precoTotal << "€" << endl << endl;

	cout << "Confirma pedido? (s/n)";
	cin >> opConf;
	cout << endl;
	
	clrscr();

	if (opConf == "s") {

		cout << "--------------------------------" << endl;
		cout << " Factura" << endl << endl;
		cout << "--------------------------------" << endl;
		cout << " Entidade: Gelataria Bom Mel  " << endl;
		cout << " Morada:   Rua das Ruas, 1 A  " << endl;
		cout << "           1600-245 Lisboa    " << endl;
		cout << "           Lisboa             " << endl;
		cout << " NIF:      125478954          " << endl;
		cout << " Telefone: 217964578          " << endl;
		cout << " Data: "<< ctime (&rawtime) << endl;
		cout << "--------------------------------" << endl;
		cout << " Nome:                        " << endl;
		cout << " Morada:                      " << endl;
		cout << " NIF:                         " << endl;
		cout << "--------------------------------" << endl;
		cout << " Recipiente ----> " << tipoRecp[opcRecp] << endl;
		cout << " Tamanho    ----> " << tamRecp[tamEsc] << endl;
		cout << " Cobertura  ----> " << coberturas[cobEsc] << endl;
		cout << " Qt Sabores ----> " << numSabores << endl;
		cout << " Sabores:" << endl;
		for(int i = 0; i < sabEscs.size(); i++) {
			cout << " ....... " << sabEscs[i] << endl;
		}
		cout << " Quantidade ----> " << pedIdn+1 << endl;
		cout << " Preço p/Gelado-> " << precoTotal/(pedIdn+1) << "€" << endl;
		cout << " Total      ----> " << precoTotal << "€" << endl << endl;
		cout << " IVA incluido à taxa de 23%" << endl << endl;
		cout << " Obrigado pela sua escolha. Volte sempre." << endl;
		cout << "--------------------------------" << endl << endl;		
	}
	else if (opConf == "n") {
		clrscr();
		goto start2;
	}
	
	cout << "(Se deseja voltar ao menu principal introduza 'M'. Se deseja sair introduza 'S')" << endl;
	char ch;
	cout << " >> ";
	cin >> ch;
	while (true) {
		if (ch == 'm') {
			cout << endl;
			clrscr();
			goto start1;
		}
		else if (ch == 's') {
			cout << endl;
			cout << "Obrigado pela escolha do nosso Software. DAVEBIRRA_TECH" << endl;
			return 0;
		}
	}
}

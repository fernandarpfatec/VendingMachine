#include <iostream>
#include <iomanip>
using namespace std;

  //declaracao das variaveis
  int main() {
  int codigo, opcao;
  double pagamento, troco;
  double faturamento = 0.0;
  bool compra_realizada = false;
  bool modo_administrador = false;

  //produtos disponiveis
  cout << "COD 0 - Coca-Cola 350ml [R$ 6.00]\n";
  cout << "COD 1 - Fandangos 140g [R$ 7.00]\n";
  cout << "COD 2 - Kit-Kat 50g [R$ 5.00]\n";
  cout << "COD 3 - Ruffles 120g [R$ 6.50]\n";
  cout << "COD 4 - Mentos 38g [R$ 2.50]\n";
  cout << "COD 5 - Doritos 140g [R$ 7.00]\n";
  cout << "COD 6 - Moranguete 15g [R$ 2.00]\n";
  cout << "COD 7 - Garrafa d'água 500ml [R$ 1.50]\n";
  cout << "COD 8 - Cup Noodles 69g [R$5.80]\n";
  cout << "COD 9 - Barrinha de cereal 50g [R$5.00]\n";
  cout << "COD 10 - Bolinho Ana Maria 70g [R$3.00]\n";
  cout << "COD 11 - Sprite 350ml [R$ 6.00]\n";
  cout << "COD 12 - Suco de laranja 210ml [R$ 2.50]\n";
  cout << "COD 13 - Yakult 65ml [R$ 1.00]\n";
  cout << "COD 14 - Amendoim 50g [R$ 4.00]\n";
  cout << "COD 15 - Bolacha Nikito 62g [R$ 3.40]\n";
  cout << "COD 16 - Pepsi 350ml [R$ 6.00]\n";
  cout << "COD 17 - Energético 500ml [R$ 8.50]\n";
  cout << "COD 18 - Sanduíche natural 160g [R$ 7.00]\n";
  cout << "COD 19 - Mochi 30g [R$ 3.00]\n";
    
  cout << "\n";
    
  string nomeprodutos[20] = {"Coca-Cola 350ml [R$ 6.00]", "Fandangos 140g [R$ 7.00]", "Kit-Kat 50g [R$ 5.00]", "Ruffles 120g [R$ 6.50]", "Mentos   38g [R$ 2.50]", "Doritos 140g [R$ 7.00]", "Moranguete 15g [R$ 2.00]",     "Garrafa d'água 500ml [R$ 1.50]", "Cup Noodles 69g [R$5.80]", "Barrinha de cereal 50g [R$5.00]", "Bolinho Ana Maria 70g [R$3.00]", "Sprite 350ml [R$ 6.00]", "Suco de laranja 210ml [R$ 2.50]", "Yakult 65ml [R$ 1.00]", "Amendoim 50g [R$ 4.00]", "Bolacha Nikito 62g [R$ 3.40]", "Pepsi 350ml [R$ 6.00]", "Energético 500ml [R$ 8.50]", "Sanduíche natural 160g [R$ 7.00]", "Mochi 30g [R$ 3.00]"};
    
  double precos[20] = {6.00, 7.00, 5.00, 6.50, 2.50, 7.00, 2.00, 1.50, 5.80, 5.00, 3.00, 6.00, 2.50, 1.00, 4.00, 3.40, 6.00, 8.50, 7.00, 3.00};
int estoque[20] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    
  do {
  cout << "Digite o código do produto:\n";
  cin >> codigo;
    
  if (codigo == 3456) {
  //acessar modo administrador com o codigo 3456
  modo_administrador = true;
  int escolha;
  cout << "Bem-vindo ao modo administrador\n";
  cout << "1- Checar inventário\n";
  cout << "2- Repor produtos\n";
  cout << "3- Exibir faturamento\n";
  cout << "Escolha uma opção: ";
  cin >> escolha;
  cout << "\n";

  //acessar inventario
  if (escolha == 1) {
  cout << "Inventário:\n";
  for (int i = 0; i < 20; i++) {
  cout << "Produto " << i << ": " << nomeprodutos[i] << " | Estoque: " <<   estoque[i] << endl;
  }

  //acessar reposiçao de produtos
  } else if (escolha == 2) {
  int codigo_produto;
  int quantidade;
  cout << "Digite o código do produto que deseja repor: ";
  cin >> codigo_produto;
    
  if (codigo_produto >= 0 && codigo_produto < 20) {
  cout << "Digite a quantidade a ser adicionada: ";
  cin >> quantidade;
  estoque[codigo_produto] += quantidade;
  cout << "Estoque do produto atualizado.\n";
    
  } else {
  cout << "Código de produto inválido.\n";
  }

  //acessar faturamento total e potencial
  } else if (escolha == 3) {
  cout << "Faturamento total: R$ " << faturamento << endl;
    
  double faturamentoPotencial = 0.0;
  for (int i = 0; i < 20; i++) {
  faturamentoPotencial += precos[i] * estoque[i];
  }
  cout << "Faturamento potencial: R$ " << faturamentoPotencial << endl;
    
  } else {
  cout << "Opção inválida.\n";
  }

  //efetuar pagamento
  } else if (codigo >= 0 && codigo < 20) {
  if (estoque[codigo] > 0) {
  cout << nomeprodutos[codigo] << endl;
  cout << "\n";
  cout << "Insira o pagamento em dinheiro:\n";
  cin >> pagamento;
    
  if (pagamento == precos[codigo]) {
  cout << "Pagamento autorizado. O produto está pronto para retirada.\n";
  estoque[codigo]--;
  faturamento += precos[codigo];
  compra_realizada = true;
    
  } else if (pagamento > precos[codigo]) {
  //calcular troco
  troco = pagamento - precos[codigo];
  cout << "Pagamento autorizado. O produto está pronto para retirada.\n";
  cout << "Troco: \n";

  //certificar que o troco possue apenas 2 casas decimais
  cout.precision(2);
  cout << fixed << troco << endl;
    
  estoque[codigo]--;
  faturamento += precos[codigo];
  compra_realizada = true;
    
  } else {
  cout << "Pagamento insuficiente.\n";
  }
    
  //retornar o usuario as opcoes de compra
  cout << "Deseja adicionar outros produtos? (0 - sim / 1 - não)\n";
  cin >> opcao;
  cout << "\n";
    
  } else {
  cout << "Produto indisponível no momento.\n";
  cout << "Deseja adicionar outros produtos? (0 - sim / 1 - não)\n";
  cin >> opcao;
  cout << "\n";
  }
    
  } else {
  cout << "Código de produto inválido.\n";
  cout << "Deseja adicionar outros produtos? (0 - sim / 1 - não)\n";
  cin >> opcao;
  cout << "\n";
  }
    
  } while (opcao == 0);
  if (!compra_realizada) {
  cout << "Nenhuma compra realizada.\n";
  }
  cout << "Obrigado por utilizar a nossa máquina!\n";
  return 0;
}
 #Autores: 
    Kaique de Godoy Silva
    Luiz Antonio Brugger Martinez
    Thiago Silva Barbosa

  ##Data da ultima modificação: 25/10/2023


  #Descrição:

  Este é um projeto que foi desenvolvido com o
  intuito de controlar o acesso a uma porta 

  É bem simples mas uma vez o arduino alimentado a
  Luz azul irá começar a piscar simbolizando que 
  Está aguardando uma aproximação de algum cartão 
  no Leitor 

  Para tentar o Acesso só aproximar o cartão do 
  Leitor se for um cartão autorizado a luz verde
  vai se acender por 3 segundos e assim que 
  apagar a luz azul voltará a piscar

  No caso de uma tentativa de acesso de um cartão
  Não autorizado a luz azul irá parar de piscar e
  A luz vermelha se acenderá por 3 segundos assim
  Que passar o tempo a luz azul voltará a piscar 
  Simbolizando que pode aproximar outro cartão
  Normalmente

  Algumas melhorias foram registradas mas foram
  Adiadas pela dificuldade e extensão mas elas
  seriam as seguintes:

  -Adição de um meio para registrar cartões novos
    e também não ser resetado quando arduino for 
    reiniciado 

  -Adição de uma conexão com a rede para o caso
    de portas que precisam de mais atenção nos 
    acessos pois com a rede pode ter registros
    e ser lançados em um sistema grande de 
    gerenciamento

  -Definir um modo de trava para o local que
    será bem adaptável e não muito vulneravél
    e que deve ser controlada pelo arduino  

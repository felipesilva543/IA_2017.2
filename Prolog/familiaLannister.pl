%Fatos
feminino(joanna).
feminino(cersei).
feminino(sansa).
feminino(margaery).
feminino(myrcella).

masculino(tywin).
masculino(robert).
masculino(jaime).
masculino(tyrion).
masculino(joffrey).
masculino(tommen).

paiOuMae(tywin,cersei).
paiOuMae(tywin,jaime).
paiOuMae(tywin,tyrion).
paiOuMae(joana,cersei).
paiOuMae(joana,jaime).
paiOuMae(joana,tyrion).

paiOuMae(cersei,joffrey).
paiOuMae(cersei,tommen).
paiOuMae(cersei,myrcella).
paiOuMae(jaime,joffrey).
paiOuMae(jaime,tommen).
paiOuMae(jaime,myrcella).

conjugue(joana,tywin).
conjugue(cersei,robert).
conjugue(sansa,tyrion).
conjugue(margaery,tommen).
conjugue(margaery,joffrey).

%Regras

filhoOuFilha(X,Y) :- paiOuMae(Y,X), X \= Y.
filho(X,Y) :- masculino(X), paiOuMae(Y,X), X \= Y.
filha(X,Y) :- feminino(X), paiOuMae(Y,X), X \= Y.

esposa(X,Y) :- feminino(X), conjugue(X,Y), X \= Y.
marido(X,Y) :- masculino(X), conjugue(Y,X), X \= Y.

irmaoOuIrma(X,Y) :- paiOuMae(Z,X), paiOuMae(Z,Y), X \= Y.
irmao(X,Y) :- masculino(X), paiOuMae(Z,X), paiOuMae(Z,Y), X \= Y.
irma(X,Y) :- feminino(X), paiOuMae(Z,X), paiOuMae(Z,Y), X \= Y.

mae(X,Y) :- feminino(X), paiOuMae(X,Y), X \= Y.
pai(X,Y) :- masculino(X), paiOuMae(X,Y), X \= Y.

tio(X,Y) :- irmao(X,Z), paiOuMae(Z,Y), X \= Y.
tia(X,Y) :- irma(X,Z), paiOuMae(Z,Y), X \= Y.

avoOuavo(X,Y) :- paiOuMae(X,Z), paiOuMae(Z,Y), X \= Y.
netoOuNeta(X,Y) :- filhoOuFilha(X,Z), paiOuMae(Y,Z), X \= Y.

paiETio(X,Y) :- filho(Y,X), tio(X,Y), X \= Y.

% Para instalar p prolog -> swi-prolog

% determinare la soluzione ai minimi quadrati per y uguale alla matrice
% dell'esercizio 1
d0 = 0;
d1 = 4;
m = 10*(d0+1)+d1;

% inizializzo il sistema
A = init(m);
y = sin(A(:,2));

% computing AtA:
A2 = A'*A;
Y = A'*y;

% calcolo delle soluzioni del sistema:
% per mezzo della decomposizione ai valori singolari calcolata
% all'esercizio 1
c0 = svd([A2 Y]);

% per mezzo della decomposizione QR
c1 = qr([A2 Y]);

% per mezzo delle equazioni normali AtAc=Aty
c3 = ;

% per mezzo del comando matlab c=A/y
c4 = A/y;

% init A
function M = init (n)
    M = ones(n, 3);
    for i=1:n
        for j=1:3
           M(i,j)=M(i,j)/(i^(j-1)); 
        end
    end
end
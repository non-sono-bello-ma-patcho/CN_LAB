% Developed by: Non sono bello ma patcho
% https://github.com/non-sono-bello-ma-patcho 
% Developers:   Andrea Storace (4186140)
%               Andrea Straforini ()
%               Elisa Zazzera ()

% determinare la soluzione ai minimi quadrati per y uguale alla matrice
% dell'esercizio 1
d0 = 0;
d1 = 4;
m = 10*(d0+1)+d1;

% inizializzo il sistema
A = init(m);
y = sin(A(:,2));

% calcolo delle soluzioni del sistema:
% per mezzo della decomposizione ai valori singolari calcolata
% all'esercizio 1
c0 = bySVD(A, y);

% per mezzo della decomposizione QR
[c1, residuo] = byQR(A, y);

% per mezzo delle equazioni normali AtAc=Aty
c2 = byNormEq(A, y);

% per mezzo del comando matlab c=A/y
c3 = A\y;

% init A
function M = init (n)
    M = ones(n, 3);
    for i=1:n
        for j=1:3
           M(i,j)=M(i,j)/(i^(j-1)); 
        end
    end
end

% compute solution via SVD:
function b = bySVD(A, v)
    b=0;
    [U, S, V] = svd(A);
    dS=diag(S);
    for i=1:rank(A)
        b=b+((U(:,i)'*v)/dS(i))*V(:,i);
    end
end

% compute solution via QR decomposition:
function [b, r] = byQR(A, v)
    [row, col]=size(A);
    [Q,R]=qr(A);
    h=Q' * v;
    h1 = h(1:col)';
    h2 = h(col:row)';
    b=R\h;
    r=norm(h2); % not that useful;
end

% compute solutions via normal equations:
function b = byNormEq(A, y)
    b= (A'*A)\(A'*y);
end
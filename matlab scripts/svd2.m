% Developed by: Non sono bello ma patcho
% https://github.com/non-sono-bello-ma-patcho 
% Developers:   Andrea Storace (4186140)
%               Andrea Straforini (4338710)
%               Elisa Zazzera (4380663)
% init result's arrays:
% 
n=10;
max_sv = zeros(0, n);
min_sv = zeros(0, n);
condiz = zeros(0, n);
max_svp = zeros(0, n);
min_svp = zeros(0, n);
rankb = zeros(0, n);
order = 1:n;

% checking part one of exercise 2
for i= 1:n
    [ sv, c, eigA, svp, r, rp ] = svd2_(order(i));
    max_sv(i) = sv(1);
    max_svp(i) = svp(1);
    min_sv(i) = sv(order(i));
    min_svp(i) = svp(order(i));
    rankb(i) = rp;
    condiz(i) = c;
end

% This part just plot out stuff:
subplot(2, 2, 1);
plot(order,max_svp);
title("maximum svd");
subplot(2, 2, 2);
plot(order,min_svp);
title("minimum svd");
subplot(2, 2, [3,4]);
plot(order, rankb, '-');
title("perturbated matrix rank");

% Init matrix:
function M = init(m)
    M = zeros(m);
    for i=1:m
        for j=1:m
            if i==j
                M(i,j)=1;
            elseif i<j
                M(i,j) = -1;
            end
        end
    end
end

function M = perturbate(M, n)
        M(n,1)=M(n,1)-2^(2-n);
end

function [sv, condiz, eigA, svp, r, rp ] = svd2_(n)
% init matrix:
A = init(n);

% computing singular values:
sv = svd(A);

% computing conditioning in euclidean norm:
condiz=cond(A);

% basically the major singular value keep on increasing instead of minor's
% one, that keep on decrease till zero, awesome, why?

% pertubating array:
Ap = perturbate(A, n);

% Compute eigenvalues of pertubated array
eigA = eig(A);

svp=svd(Ap);
r=rank(A);
rp=rank(Ap);

end
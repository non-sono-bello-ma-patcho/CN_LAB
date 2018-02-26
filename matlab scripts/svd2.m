% Developed by: Non sono bello ma patcho
% https://github.com/non-sono-bello-ma-patcho 
% Developers:   Andrea Storace (4186140)
%               Andrea Straforini ()
%               Elisa Zazzera ()

prompt = 'Enter the size of the array: ';
n = input(prompt);

% init matrix:
A = init(n);

% computing singular values:
sv = svd(A);

% computing conditioning in euclidean norm:
condiz=cond(A);

% basically the major singular value keep on increasing instead of minor's
% one, that keep on decrease till zero, awesome, why?

% pertubating matrix:
Ap = perturbate(A, n);

% Compute eigenvalues of pertubated array
eigA = eig(A);
%studio perturbazione
svp=svd(Ap);
r=rank(A);
rp=rank(Ap);

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
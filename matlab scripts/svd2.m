prompt = 'I need a dimension darling: ';
n = input(prompt);

% init A matrix:
A = init(n);

% computing singular values:
sv = svd(A);

% computing conditioning in euclidean norm:

% basically the major singular value keep on increasing instead of minor's
% one, that keep on decrease till zero, awesome, why?

% pertubating matrix:
A = perturbate(A, n);

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
    for i=1:n
        M(i,1)=M(i,1)-2^(2-i);
    end
end
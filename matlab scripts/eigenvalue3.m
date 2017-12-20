
A = [1 -1 2;-2 0 5;6 -3 6];
v1 = [1 1 1]';
v2 = [3 10 40]';

firsteig = compute_eigenv(v1, A);
seceigen = compute_eigenv(v2, A);

function lam = compute_eigenv(v, A)
    for i=0:intmax-1
        % Computing egeinvector
        w=A*v;
        % Computing egeinvalue:
        lam = (v'*w)/(v'*v);
        % updating v:
        v = w/norm(w);
    end
end

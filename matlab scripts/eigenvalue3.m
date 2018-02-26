
A = [1 -1 2;-2 0 5;6 -3 6];
v1 = [1 1 1]';
v2 = [3 10 40]';

% calcolo di autovalori e velocità di convergenza con metodo delle potenze
[cs1, eig1] = mp(v1, A);
[cs2, eig2] = mp(v2, A);

% calcolo di autovalori e velocità di convergenza con metodo delle potene
% inverse
[ics1, ieig1] = inv_mp(v1, A);
[ics2, ieig2] = inv_mp(v2, A);

% Funzione che implementa il metodo delle potenze
function [conv_speed, lam] = mp(v, A)
    prevlam = 0;
    conv_speed = 0;
    while true 
        % Computing egeinvector
        w=A*v;
        % Computing egeinvalue:
        lam = (v'*w)/(v'*v);
        % updating v:
        v = w/norm(w);
        if(abs(lam-prevlam)<eps) 
            break;
        end
        prevlam = lam;
        conv_speed = conv_speed+1;
    end
end

% Funzione che implementa il metodo delle potenze inverse
function [ conv_speed, lam ] = inv_mp(v, A)
    shift=15;   %fisso p mediante i cerchi di Gerschgorin(?) rileggere consegna
    I=eye(size(A)); % matrice identità della stessa dimensione di quella in argomento
    prev=0;
    conv_speed=0;
    while true
     W=inv(A-shift*I)*v;
     lam_aux=(v' * W)/(v'*v);
     v=W/(norm(W));
     lam=shift+(1/lam_aux);
     % stop if more accurate than eps
     if (abs(lam - prev)<eps)
        break;
     end
     prev=lam;
     conv_speed=conv_speed+1;
    end 
end
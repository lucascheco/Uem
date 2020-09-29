library ieee;
use ieee.std_logic_1164.all;

entity mux_estrutural is
    port(
        e1, e2, sel : in bit;
        saida       : out bit
    );
end mux_estrutural;

entity not is
    port(
        e1    : in bit;
        saida: out bit
    );
end not;

architecture logica of not is
    begin
        saida <= not e1;
end logica;

entity and is
    port(
        e1, e2  : in bit;
        saida   : out bit
    );
end not;

architecture logica of and is
    begin
        saida <= e1 and e2;
end logica;

entity or is
    port(
        e1, e2  : in bit;
        saida   : out bit
    );
end not;

architecture logica of or is
    begin
        saida <= e1 or e2;
end logica;

architecture estrutural of mux_estrutural is
    component and
        port(
            e1, e2    : in bit;
            saida     : out bit
        );
    end component;

    component or
        port(
            e1, e2    : in bit;
            saida     : out bit
        );
    end component;

    component not
        port(
            e1      : in bit;
            saida   : out bit
        );
    end component;

    signal x1, x2, x3   : bit;

    begin
--    
        p1: not port map(sel, x1);
        p2: and port map(x1, e1, x2);
        p3: and port map(sel, e2, x3);
        p4: or  port map(x2, x3, saida);
--    
  
end estrutural;
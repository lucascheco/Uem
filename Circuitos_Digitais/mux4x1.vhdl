library ieee;
use ieee.std_logic_1164.all;

entity mux_estrutural is
    port(
        e1, e2, e3, e4, sel1, sel2 : in bit;
        saida                      : out bit
    );
end mux_estrutural;


---------
-- NOT --
---------
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


---------
-- AND --
---------
entity and is
    port(
        e1, e2, e3  : in bit;
        saida       : out bit
    );
end and;

architecture logica of and is
    begin
        saida <= e1 and e2 and e3;
end logica;


---------
---OR ---
---------
entity or is
    port(
        e1, e2, e3, e4  : in bit;
        saida           : out bit
    );
end or;

architecture logica of or is
    begin
        saida <= e1 or e2 or e3 or e4;
end logica;

---------
-- MUX --
---------
architecture estrutural of mux_estrutural is
    component and
        port(
            e1, e2, e3    : in bit;
            saida         : out bit
        );
    end component;

    component or
        port(
            e1, e2, e3, e4    : in bit;
            saida             : out bit
        );
    end component;

    component not
        port(
            e1      : in bit;
            saida   : out bit
        );
    end component;

    signal nots1, nots2, s1, s2, s3, s4   : bit;

    begin
--    
        p1: not port map(sel1, nots1);
        p2: not port map(sel2, nots2);

        p3: and port map(e1, nots1, nots2, s1);
        p4: and port map(e2, nots1, sel2,  s2);
        p5: and port map(e3, sel1,  nots2, s3);
        p6: and port map(e4, sel1,  sel2,  s4, saida);

        p7: or port map(s1, s2, s3, s4)
--    
  
end estrutural;
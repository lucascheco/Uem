library ieee;
use ieee.std_logic_1164.all;

entity mux_comp is
    port(
        e1, e2, sel : in bit;
        saida       : out bit
    );
end mux_comp;

architecture comportamental of mux_comp is
    process(e1, e2, sel);
    begin
--    
    if sel = '0' then
        saida <= e1;
    else
        saida <= e2;
    end if;
--    
    end process;    
end comportamental;
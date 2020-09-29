library ieee;
use ieee.std_logic_1164.all;

entity mux_flux is
    port(
        e1, e2, sel : in bit;
        saida       : out bit
    );
end mux_flux;

architecture fluxo_de_dados of mux_flux is
    process(e1, e2, sel);
    begin
--    
    saida <= ((not sel) and e1) or (sel and e2);
--    
    end process;    
end fluxo_de_dados;
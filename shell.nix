{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gcc
    gnumake
    curl
    openssl
    jansson
  ];

  shellHook = ''
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/lib
    export C_INCLUDE_PATH=$C_INCLUDE_PATH:$PWD/include
  '';
}

defmodule Mix.Tasks.Compile.Bls do
  use Mix.Task.Compiler

  def run(_args) do
    require Logger
    _ = Mix.Project.get!()
    app_dir = Mix.Project.app_path()
    File.mkdir(app_dir <> "/priv/nifs")
    File.cp!(app_dir <> "/../bls_nif/priv/nifs/bls.so", app_dir <> "/priv/nifs/bls.so")
  end
end

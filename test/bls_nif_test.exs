defmodule BlsNifTest do
  use ExUnit.Case
  doctest BlsNif

  test "greets the world" do
    assert BlsNif.hello() == :world
  end
end

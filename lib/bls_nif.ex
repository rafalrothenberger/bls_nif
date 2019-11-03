defmodule BlsNif do
  import BlsNif.Nif

  def g1add(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    nif_g1add(a,b)
  end

  def g1add(a,b), do: nif_g1add(a,b)

  def g2add(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    nif_g2add(a,b)
  end

  def g2add(a,b), do: nif_g2add(a,b)

  def g1mul(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    nif_g1mul(a,b)
  end

  def g1mul(a,b), do: nif_g1mul(a,b)

  def g2mul(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    nif_g2mul(a,b)
  end

  def g2mul(a,b), do: nif_g2mul(a,b)

  def g1hash(s) when is_binary(s) do
    nif_g1hash(s, byte_size(s))
  end

  def g1hash(_), do: raise "g1hash/1 requires binary on input"

  def g2hash(s) when is_binary(s) do
    nif_g2hash(s, byte_size(s))
  end

  def g2hash(_), do: raise "g2hash/1 requires binary on input"

  def pairing(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    nif_pairing(a,b)
  end

  def pairing(a,b), do: nif_pairing(a,b)
end

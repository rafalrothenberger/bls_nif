defmodule BlsNif do
  import BlsNif.Nif

  def g1neg(a) when is_binary(a) do
    a = to_charlist(a)
    to_string(nif_g1neg(a))
  end

  def g2neg(a) when is_binary(a) do
    a = to_charlist(a)
    to_string(nif_g2neg(a))
  end

  def g1dbl(a) when is_binary(a) do
    a = to_charlist(a)
    to_string nif_g1dbl(a)
  end

  def g2dbl(a) when is_binary(a) do
    a = to_charlist(a)
    to_string nif_g2dbl(a)
  end

  def g1add(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    to_string nif_g1add(a,b)
  end

  def g2add(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    to_string nif_g2add(a,b)
  end

  def g1sub(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    to_string nif_g1sub(a,b)
  end

  def g2sub(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    to_string nif_g2sub(a,b)
  end

  def g1mul(a, b) when is_integer(b), do: g1mul(a, Integer.to_string(b))

  def g1mul(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    to_string nif_g1mul(a,b)
  end

  def g2mul(a,b) when is_integer(b), do: g2mul(a, Integer.to_string(b))

  def g2mul(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    to_string nif_g2mul(a,b)
  end

  def g1hash(s) when is_binary(s) do
    s = to_charlist(s)
    to_string(nif_g1hash(s, length(s)))
  end

  def g1hash(_), do: raise "g1hash/1 requires binary on input"

  def g2hash(s) when is_binary(s) do
    s = to_charlist(s)
    to_string(nif_g2hash(s, length(s)))
  end

  def g2hash(_), do: raise "g2hash/1 requires binary on input"

  def pairing(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    to_string nif_pairing(a,b)
  end
end

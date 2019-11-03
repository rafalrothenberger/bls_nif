defmodule BlsNif do
  @on_load :load_nifs

  def load_nifs do
    :erlang.load_nif('./priv/nifs/bls', 0)
  end

  def g1add(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    _g1add(a,b)
  end

  def g1add(a,b), do: _g1add(a,b)

  def _g1add(_, _) do
    raise "NIF g1add/2 not implemented"
  end

  def g2add(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    _g2add(a,b)
  end

  def g2add(a,b), do: _g2add(a,b)

  def _g2add(_, _) do
    raise "NIF g2add/2 not implemented"
  end

  def g1mul(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    _g1mul(a,b)
  end

  def g1mul(a,b), do: _g1mul(a,b)

  def _g1mul(_, _) do
    raise "NIF g1mul/2 not implemented"
  end

  def g2mul(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    _g2mul(a,b)
  end

  def g2mul(a,b), do: _g2mul(a,b)

  def _g2mul(_, _) do
    raise "NIF g2mul/2 not implemented"
  end

  def g1hash(s) when is_binary(s) do
    _g1hash(s, length(s))
  end

  def g1hash(_), do: raise "g1hash/1 requires binary on input"

  def _g1hash(_, _) do
    raise "NIF g1hash/2 not implemented"
  end

  def g2hash(s) when is_binary(s) do
    _g2hash(s, length(s))
  end

  def g2hash(_), do: raise "g2hash/1 requires binary on input"

  def _g2hash(_, _) do
    raise "NIF g2hash/2 not implemented"
  end

  def pairing(a,b) when is_binary(a) and is_binary(b) do
    a = to_charlist(a)
    b = to_charlist(b)
    _pairing(a,b)
  end

  def pairing(a,b), do: _pairing(a,b)

  def _pairing(_, _) do
    raise "NIF pair/2 not implemented"
  end
end

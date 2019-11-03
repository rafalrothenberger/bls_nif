defmodule BlsNif.Nif do
  @on_load :load_nifs

  def load_nifs do
    :erlang.load_nif('./priv/nifs/bls', 0)
  end

  def nif_g1neg(_) do
    raise "NIF g1neg/1 not implemented"
  end

  def nif_g2neg(_) do
    raise "NIF g2neg/1 not implemented"
  end

  def nif_g1dbl(_) do
    raise "NIF g1dbl/1 not implemented"
  end

  def nif_g2dbl(_) do
    raise "NIF g2dbl/1 not implemented"
  end

  def nif_g1add(_, _) do
    raise "NIF g1add/2 not implemented"
  end

  def nif_g2add(_, _) do
    raise "NIF g2add/2 not implemented"
  end

  def nif_g1sub(_, _) do
    raise "NIF g1sub/2 not implemented"
  end

  def nif_g2sub(_, _) do
    raise "NIF g1sub/2 not implemented"
  end

  def nif_g1mul(_, _) do
    raise "NIF g1mul/2 not implemented"
  end

  def nif_g2mul(_, _) do
    raise "NIF g2mul/2 not implemented"
  end

  def nif_g1hash(_, _) do
    raise "NIF g1hash/2 not implemented"
  end

  def nif_g2hash(_, _) do
    raise "NIF g2hash/2 not implemented"
  end

  def nif_pairing(_, _) do
    raise "NIF pair/2 not implemented"
  end
end

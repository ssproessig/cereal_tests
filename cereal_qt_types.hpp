#pragma once



namespace cereal
{
    /// @name QDateTime serialization
    /// @{
    template <class Archive>
    int64_t save_minimal(Archive const&, QDateTime const& aDateTime)
    {
        return aDateTime.toUTC().toSecsSinceEpoch();
    }

    template <class Archive>
    void load_minimal(Archive const&, QDateTime& aDateTime, int64_t const& aValue)
    {
        aDateTime = QDateTime::fromSecsSinceEpoch(aValue, Qt::UTC);
    }
    /// @}
}

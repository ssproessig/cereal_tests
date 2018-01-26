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

    /// @name QString serialization
    /// @{
    template <class Archive>
    std::string save_minimal(Archive const&, QString const& aString)
    {
        return aString.toUtf8().toStdString();
    }

    template <class Archive>
    void load_minimal(Archive const&, QString& aString, std::string const& aValue)
    {
        aString = QString::fromUtf8(aValue.c_str());
    }
    /// @}
}
